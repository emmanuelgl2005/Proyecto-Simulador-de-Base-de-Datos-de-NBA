/*
 * NBAdata.cpp
 *
 *  Created on: 24/10/2025
 *      Author: Emmanuel Garcia Lopez
 */

#include "NBAdata.h"
#include "bst.h"
#include "iostream"
#include <fstream>

NBAdata::NBAdata() {
    _3Ppercent = 0.000; 
    _2Ppercent = 0.000; 
    team = ""; 
    rk = 0;
    wins = 0;
    losses = 0; 
    }

NBAdata::NBAdata(float _3Ppercent, float _2Ppercent, const string& equipo, int rk) {
    this->_3Ppercent = _3Ppercent; 
    this->_2Ppercent = _2Ppercent; 
    this->team = equipo; 
    this->rk = rk; 
    this->wins = wins;
    this->losses = losses;
    }

void NBAdata::sortBy3Ppercent(vector<NBAdata> &data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int temp = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j]._3Ppercent > data[temp]._3Ppercent) {
                temp = j;
            }
        }
        if (temp != i) {
            swap(data[i], data[temp]);
        }
    }
}

void NBAdata::sortBy2Ppercent(vector<NBAdata> &data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int temp = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j]._2Ppercent > data[temp]._2Ppercent) {
                temp = j;
            }
        }
        if (temp != i) {
            swap(data[i], data[temp]);
        }
    }
}

void NBAdata::sortByWins(vector<NBAdata> &data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j].wins > data[maxIdx].wins) {
                maxIdx = j;
            }
        }
        swap(data[i], data[maxIdx]);
    }
}

void NBAdata::sortByLosses(vector<NBAdata> &data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j].losses > data[maxIdx].losses) {
                maxIdx = j;
            }
        }
        swap(data[i], data[maxIdx]);
    }
}

void NBAdata::searchTeam(const vector<NBAdata>& data) {
    string team_name; 
    cout << "Nombre del equipo a buscar: ";
    cin.ignore(); 
    getline(cin, team_name);
    team_name = toLowerCase(team_name);  

    for (const NBAdata& equipo : data) {
        string equipoLowerCase = equipo.team; 
        equipoLowerCase = toLowerCase(equipoLowerCase); 

        if (equipoLowerCase == team_name) {
            cout << "Team: " << equipo.team << " 3p%: " << equipo._3Ppercent << " 2p%: " << equipo._2Ppercent << " Ranking: " << equipo.rk << endl;
            return; 
        }
    }
    cout << "Equipo no encontrado" << endl;
}

void NBAdata::accessRk(const vector<NBAdata>& data) {
    int ranking; 
    cout << "Quien esta en la posicion: ";
    cin >> ranking; 

    for (const NBAdata& team : data) {
        if (team.rk == ranking) {
            cout << "Ranking: " << team.rk << " Team: " << team.team << " 3p%: " << team._3Ppercent << " 2p%: " << team._2Ppercent << endl;
            return; 
        }
    }
    cout << "Solo hay 30 equipos." << endl;
}

void NBAdata::showMenu() {
    cout << endl; 
    cout << "==== Menu de simulador de base de datos de NBA ====" << endl;
    cout << "1. Mostrar tabla de posiciones y datos" << endl;
    cout << "2. Ordenar por %, W o L" << endl;
    cout << "3. Buscar por nombre de equipo" << endl;
    cout << "4. Acceder por numero de ranking" << endl;
    cout << "5. Insertar equipo" << endl;
    cout << "6. Seleccione Favorito" << endl;
    cout << "0. Salir" << endl; 
    cout << "Ingrese su opcion: " << endl; 
}

void NBAdata::manageMenu(vector<NBAdata> &data, MaxHeap &favoriteHeap) {
    int option;
    bool salir = false;
    NBAdata jugador;

    BST rankingBST; 
    TreeNode* resultNode = nullptr;

    for (const NBAdata &item : data) {
        rankingBST.insert(item.rk, item.team, item._3Ppercent, item._2Ppercent);
    }

    while (!salir) {
        showMenu();
        cin >> option;

        switch (option) {
            case 0:
                salir = true;
                cout << "Gracias, vuelva pronto" << endl;
                break;

            case 1:
                cout << endl;
                jugador.displayWithFavorite(data, favoriteHeap);
                break;

            case 2:
            cout << endl;
            int sortOption;
            do {
                cout << "==== Ordenar ====" << endl;
                cout << "1. Por porcentaje de 3P" << endl;
                cout << "2. Por porcentaje de 2P" << endl;
                cout << "3. Por partidos ganados (W)" << endl;
                cout << "4. Por partidos perdidos (L)" << endl;
                cout << "0. Salir al menu principal" << endl;
                cin >> sortOption;

                switch (sortOption) {
                    case 0:
                        break;
                    case 1:
                        jugador.displaySortedWithFavorite(data, favoriteHeap, true);
                        break;
                    case 2:
                        jugador.displaySortedWithFavorite(data, favoriteHeap, false);
                        break;
                    case 3:
                        jugador.displayWinsWithFavorite(data, favoriteHeap);
                        break;
                    case 4:
                        jugador.displayLossesWithFavorite(data, favoriteHeap);
                        break;
                    default:
                        cout << "Opción no valida. Intente de nuevo." << endl;
                        break;
                }
                cout << endl;
            } while (sortOption != 0);
            break;

            case 3:
                cout << endl;
                cout << "==== Buscador por equipos ====" << endl;
                jugador.searchTeam(data);
                break;

            case 4:
                cout << endl;
                cout << "==== Acceso por ranking ====" << endl;
                int accessRanking;
                cout << "Ingrese el numero de ranking al que desea acceder: "; 
                cin >> accessRanking; 
                resultNode = rankingBST.searchByRanking(accessRanking); 
                if (resultNode) {
                    cout << "Team: " << resultNode->team << ", 3P%: " << resultNode->_3Ppercent << ", 2P%: " << resultNode->_2Ppercent << ", Ranking: " << resultNode->rk << endl;
                } else {
                    cout << "No se encontro ningun equipo con ese ranking." << endl;
                }
                break;
            
            case 5: {
                cout << endl;
                cout << "==== Insertar un nuevo equipo ====" << endl;

                int nextRanking = data.size() + 1;
                string equipo;
                float p3, p2;

                cout << "Ingrese el nombre del equipo: ";
                cin.ignore();
                getline(cin, equipo);

                cout << "Ingrese el porcentaje de triples (3P%): ";
                cin >> p3;

                cout << "Ingrese el porcentaje de tiros de dos puntos (2P%): ";
                cin >> p2;

                NBAdata newTeam(p3, p2, equipo, nextRanking); 
                data.push_back(newTeam);
                rankingBST.insert(nextRanking, equipo, p3, p2);

                cout << "Equipo insertado exitosamente." << endl;
                break;
            }
            
            case 6: {
                cout << endl;
                int rankedOption;
                do {
                    cout << "==== Favorito ====" << endl;
                    cout << "1. Seleccionar equipo favorito" << endl;
                    cout << "2. Ver equipo favorito" << endl;
                    cout << "0. Volver al menu principal" << endl;
                    cin >> rankedOption;
                    
                    switch (rankedOption) {
                        case 1:
                            jugador.selectFavoriteTeam(favoriteHeap, data);
                            break;
                        case 2:
                            jugador.viewFavoriteTeam(favoriteHeap);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opción no valida." << endl;
                    }
                } while (rankedOption != 0);
                break;
            }
            
            case 7:
                jugador.viewFavoriteTeam(favoriteHeap);
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    }
}

void NBAdata::mergeSortBy3Ppercent(vector<NBAdata>& data, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        vector<NBAdata> leftArray(n1);
        vector<NBAdata> rightArray(n2);

        for (int i = 0; i < n1; i++) {
            leftArray[i] = data[left + i];
        }
        for (int i = 0; i < n2; i++) {
            rightArray[i] = data[middle + 1 + i];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (leftArray[i]._3Ppercent >= rightArray[j]._3Ppercent) {
                data[k] = leftArray[i];
                i++;
            } else {
                data[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            data[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            data[k] = rightArray[j];
            j++;
            k++;
        }
    }

void NBAdata::mergeSortBy2Ppercent(vector<NBAdata>& data, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        vector<NBAdata> leftArray(n1);
        vector<NBAdata> rightArray(n2);

        for (int i = 0; i < n1; i++) {
            leftArray[i] = data[left + i];
        }
        for (int i = 0; i < n2; i++) {
            rightArray[i] = data[middle + 1 + i];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (leftArray[i]._2Ppercent >= rightArray[j]._2Ppercent) {
                data[k] = leftArray[i];
                i++;
            } else {
                data[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            data[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            data[k] = rightArray[j];
            j++;
            k++;
        }
    }

void NBAdata::mergeSort(vector<NBAdata>& data, bool sortBy3) {
        int n = data.size();
        int currentSize;

        for (currentSize = 1; currentSize < n; currentSize *= 2) {
            for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currentSize) {
                int middle = min(leftStart + currentSize - 1, n - 1);
                int rightEnd = min(leftStart + 2 * currentSize - 1, n - 1);
            if (sortBy3) {
                mergeSortBy3Ppercent(data, leftStart, middle, rightEnd);
            } else {
                mergeSortBy2Ppercent(data, leftStart, middle, rightEnd);
            }

            }
        }
    }

string NBAdata::toLowerCase(const string str)
{
    string result;
    for (char c : str) {
    result += tolower(c);
}
    return result;
}

void NBAdata::selectFavoriteTeam(MaxHeap &favoriteHeap, const vector<NBAdata> &data) {
    string teamName;
    cout << "\n==== Seleccionar equipo favorito ====" << endl;
    cout << "Nombre del equipo: ";
    cin.ignore();
    getline(cin, teamName);
    teamName = toLowerCase(teamName);
    
    for (const NBAdata& equipo : data) {
        string equipoLowerCase = toLowerCase(equipo.team);
        
        if (equipoLowerCase == teamName) {
            // Actualizar prioridad si el equipo ya existe en el heap
            favoriteHeap.updatePriority(equipo.team, 1);
            
            // Si el heap está vacío o el equipo no estaba, insertarlo
            if (favoriteHeap.size() == 0 || favoriteHeap.isEmpty()) {
                favoriteHeap.insert(equipo.rk, equipo.team, equipo._3Ppercent, equipo._2Ppercent, 1);
            }
            
            cout << "✓ " << equipo.team << " ha sido establecido como equipo favorito." << endl;
            cout << "Estadisticas del equipo:" << endl;
            cout << "  Ranking: " << equipo.rk << endl;
            cout << "  3P%: " << equipo._3Ppercent << endl;
            cout << "  2P%: " << equipo._2Ppercent << endl;
            return;
        }
    }
    
    cout << "✗ Equipo no encontrado. Intente nuevamente." << endl;
}

void NBAdata::viewFavoriteTeam(MaxHeap &favoriteHeap) {
    cout << "\n==== Mi equipo favorito ====" << endl;
    
    if (favoriteHeap.isEmpty()) {
        cout << "No has seleccionado un equipo favorito aun." << endl;
        return;
    }
    
    try {
        HeapNode favorite = favoriteHeap.getMax();
        cout << "Tu equipo favorito es: " << favorite.team << endl;
        cout << "  Ranking: " << favorite.rk << endl;
        cout << "  3P%: " << favorite._3Ppercent << endl;
        cout << "  2P%: " << favorite._2Ppercent << endl;
        cout << "  Estado: [FAVORITO ]" << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void NBAdata::displayWithFavorite(const vector<NBAdata> &data, MaxHeap &favoriteHeap) {
    cout << "\n==== Tabla general ====" << endl;
    
    // Mostrar favorito primero si existe
    if (!favoriteHeap.isEmpty()) {
        try {
            HeapNode favorite = favoriteHeap.getMax();
            cout << "[FAVORITO] Ranking: " << favorite.rk << " | Team: " << favorite.team 
                << " | 3p%: " << favorite._3Ppercent << " | 2p%: " << favorite._2Ppercent << endl;
        
        } catch (const exception& e) {
            // Si hay error, continuar sin favorito
        }
    }
    
    // Mostrar resto de equipos
    for (const NBAdata &extracted_data : data) {
        cout << "Ranking: " << extracted_data.rk << " Team: " << extracted_data.team 
            << " 3p%: " << extracted_data._3Ppercent << " 2p%: " << extracted_data._2Ppercent << endl;
    }
}

void NBAdata::displaySortedWithFavorite(vector<NBAdata> &data, MaxHeap &favoriteHeap, bool sortBy3) {
    string sortType = sortBy3 ? "3P" : "2P";
    cout << "\n==== Ordenar por porcentaje de: " << sortType << " ====" << endl;
    
    // Ejecutar el merge sort
    mergeSort(data, sortBy3);
    
    // Mostrar favorito primero si existe
    if (!favoriteHeap.isEmpty()) {
        try {
            HeapNode favorite = favoriteHeap.getMax();
            string favoriteType = sortBy3 ? "3P%" : "2P%";
            cout << "[FAVORITO] Team: " << favorite.team << " | " << favoriteType << ": " 
                << (sortBy3 ? favorite._3Ppercent : favorite._2Ppercent) 
                << " | " << (sortBy3 ? "2P%" : "3P%") << ": " 
                << (sortBy3 ? favorite._2Ppercent : favorite._3Ppercent) 
                << " | Rank: " << favorite.rk << endl;
            
        } catch (const exception& e) {
            // Si hay error, continuar sin favorito
        }
    }
    
    // Mostrar resto de equipos ordenados
    for (const NBAdata &item : data) {
        cout << "Team: " << item.team << " | " << sortType << "%: " 
            << (sortBy3 ? item._3Ppercent : item._2Ppercent) 
            << " | " << (sortBy3 ? "2P%" : "3P%") << ": " 
            << (sortBy3 ? item._2Ppercent : item._3Ppercent) 
            << " | Rank: " << item.rk << endl;
    }
}

void NBAdata::displayWinsWithFavorite(vector<NBAdata> &data, MaxHeap &favoriteHeap) {
    cout << "\n==== Ordenar por partidos ganados (W) ====" << endl;
    
    // Ejecutar el sort
    sortByWins(data);
    
    // Mostrar favorito primero si existe
    if (!favoriteHeap.isEmpty()) {
        try {
            HeapNode favorite = favoriteHeap.getMax();
            cout << "[FAVORITO] Team: " << favorite.team << " | Wins: " << favorite.rk 
                << " | Losses: " << favorite.rk << endl;
            
        } catch (const exception& e) {
            // Si hay error, continuar sin favorito
        }
    }
    
    // Mostrar resto de equipos
    for (const NBAdata &item : data) {
        cout << "Team: " << item.team << " | Wins: " << item.wins << " | Losses: " << item.losses << endl;
    }
}

void NBAdata::displayLossesWithFavorite(vector<NBAdata> &data, MaxHeap &favoriteHeap) {
    cout << "\n==== Ordenar por partidos perdidos (L) ====" << endl;
    
    // Ejecutar el sort
    sortByLosses(data);
    
    // Mostrar favorito primero si existe
    if (!favoriteHeap.isEmpty()) {
        try {
            HeapNode favorite = favoriteHeap.getMax();
            cout << "[FAVORITO] Team: " << favorite.team << " | Wins: " << favorite.rk 
                << " | Losses: " << favorite.rk << endl;
            
        } catch (const exception& e) {
            // Si hay error, continuar sin favorito
        }
    }
    
    // Mostrar resto de equipos
    for (const NBAdata &item : data) {
        cout << "Team: " << item.team << " | Wins: " << item.wins << " | Losses: " << item.losses << endl;
    }
}

void NBAdata::saveReport(const vector<NBAdata> &data, MaxHeap &favoriteHeap, const string &filename) {
    ofstream archivo_salida(filename);
    
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return;
    }
    
    archivo_salida << "================== REPORTE NBA ==================" << endl;
    
    // Guardar el equipo favorito si existe
    if (!favoriteHeap.isEmpty()) {
        try {
            HeapNode favorite = favoriteHeap.getMax();
            archivo_salida << "    EQUIPO FAVORITO    " << endl;
            archivo_salida << "Ranking: " << favorite.rk << " | Team: " << favorite.team 
                                << " | 3P%: " << favorite._3Ppercent << " | 2P%: " << favorite._2Ppercent << endl;
            archivo_salida << "─────────────────────────────────────────────────\n" << endl;
        } catch (const exception& e) {
            archivo_salida << "No hay equipo favorito seleccionado.\n" << endl;
        }
    } else {
        archivo_salida << "No hay equipo favorito seleccionado.\n" << endl;
    }
    
    // Guardar tabla completa
    archivo_salida << "TABLA DE POSICIONES GENERAL:" << endl;
    archivo_salida << "────────────────────────────────────────────────────────────────" << endl;
    
    for (const NBAdata &team : data) {
        archivo_salida << "Ranking: " << team.rk << " | Team: " << team.team 
                    << " | 3P%: " << team._3Ppercent << " | 2P%: " << team._2Ppercent 
                    << " | Wins: " << team.wins << " | Losses: " << team.losses << endl;
    }
    
    archivo_salida << "\n════════════════════════════════════════════════════════════════" << endl;
    archivo_salida << "Total de equipos: " << data.size() << endl;
    
    archivo_salida.close();
    cout << "\n Reporte guardado exitosamente en: " << filename << endl;
}