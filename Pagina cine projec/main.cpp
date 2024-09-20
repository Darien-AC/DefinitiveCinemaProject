#include "define.h"
#include "Movie.h"
#include "Schedule.h"
#include "Theater.h"
#include "Reservation.h"
#include "Sale.h"

int main()
{
	/*string movieName1 = "BULLET TRAIN";
	string movieYear1 = "2022";
	string movieCountry1 = "Estados Unidos";
	string movieSinopsis1 = "La pelicula narra el camino que deberan seguir siete asesinos, cada uno con su propio objetivo, cuando deciden subirse aun tren bala japones, conocido como el mas veloz del mundo, para saldar cuentas entre ellos, desplegando no solo accion,sino tambien comedia.";
	string movieDuration1 = "110min";

	string movieName2 = "AVENGERS: END GAME";
	string movieYear2 = "2019";
	string movieCountry2 = "Estados Unidos";
	string movieSinopsis2 = "Despues de los eventos devastadores de Avengers: Infinity War, el universo esta en ruinas debido a las acciones de      Thanos, el Titan Loco. Con la ayuda de los aliados que quedaron, los Vengadores deben reunirse una vez mas para deshacersus acciones y restaurar el orden en el universo de una vez por todas, si importar cuales son las consecuencias.";
	string movieDuration2 = "130min";

	string movieName3 = "HAIKYUU: LA BATALLA DEL BASURERO";
	string movieYear3 = "2024";
	string movieCountry3 = "Japon";
	string movieSinopsis3 = "El enfrentamiento definitivo entre los dos equipos mas queridos de la franquicia, el Karasuno vs Nekoma, cuervos contra gatos, la tan esperada Batalla del basurero hara que la tension aumente, ya que ambos equipos estan decididos a salir   victoriosos en el campeonato nacional de voleibol.";
	string movieDuration3 = "85min";

	string movieName4 = "DOCTOR STRANGE: MULTIVERSE OF MADNESS";
	string movieYear4 = "2022";
	string movieCountry4 = "Estados Unidos";
	string movieSinopsis4 = "Despues de los eventos de Avengers: Endgame, Doctor Strange continua su investigacion sobre la piedra del tiempo. Sin   embargo, un nuevo enemigo busca destruir a cada hechicero restante en la Tierra y desatar un mal indescriptible.";
	string movieDuration4 = "126min";*/

	string movieName;
	string movieYear;
	string movieCountry;
	string movieSinopsis;
	string movieDuration;

	//salas
	string* rooms = nullptr;
	Theater Room1;
	int totalRooms;

	//horarios
	string* schedules = nullptr;
	Schedule schedule1;

	//reserva
	Reservation reserves;

	//venta
	Sale sales;

	string roomNumber1 = "Room 1";
	int roomPrice1 = 3200;
	char matrix[ROWS][COLUMNS];

	int seatsNumber[COLUMNS];
	int userChoice = 0, userChoice2 = 0, userChoice3 = 0, userChoice4 = 0;

	bool flag = true;
	bool fileFlag = true;
	bool maintenanceFlag = true;
	bool reserveFlag = true;

	Movie movie1(movieName, movieSinopsis, movieCountry, movieYear, movieDuration);

	while (flag)
	{
		cout << CYAN " * * * * * " BLUE "MENU" CYAN " * * * * * * *\n";
		cout << CYAN"*"  GREEN"  1) ARCHIVO" CYAN"                 *\n";
		cout << CYAN"*"  GREEN"  2) MANTENIMIENTO" CYAN"           *\n";
		cout << CYAN"*"  GREEN"  3) RESERVA " CYAN"                *\n";
		cout << CYAN"*"  GREEN"  4) VENTA " CYAN"                  *\n";
		cout << " * * * * * * * * * * * * * * *\n\n" RESET;
		cout << "Seleccione una opcion: ";
		cin >> userChoice;
		cout << endl << endl;
		system("cls");


		switch (userChoice)
		{
		case 1://ARCHIVO

			fileFlag = true;

			while (fileFlag)
			{
				cout << CYAN " * ** " BLUE "SUBMENU" CYAN " ** ** *\n";
				cout << "* " GREEN "1) ACERCA DE" CYAN "         *\n";
				cout << "*" RED " 2) SALIR             " CYAN "*\n";
				cout << CYAN " * ** ** ** ** ** ** *\n\n" RESET;
				cout << "Seleccione una opcion: ";
				cin >> userChoice2;
				cout << endl << endl;
				system("cls");


				switch (userChoice2)
				{
				case 1:

					cout << YELLOW "===================================================\n";
					cout << YELLOW "||" RESET "                NUEVA CINEMA SA                " YELLOW "||\n";
					cout << YELLOW "||" PURPLE "                 Fundado por:                  " YELLOW "|| \n";
					cout << YELLOW "||" PURPLE "            Lc.Darien Arroyo Castro            " YELLOW "|| \n";
					cout << YELLOW "||" BLUE "        El dia 10 de noviembre de 2024         " YELLOW "||\n";
					cout << YELLOW "||" GREEN " El mejor lugar para disfrutar de una pelicula " YELLOW "||\n";
					cout << YELLOW "===================================================\n\n" RESET;
					system("pause");
					system("cls");

					fileFlag = false;

					break;

				case 2:

					fileFlag = false;
					flag = false;
					cout << RED "Saliendo...." RESET << endl;

					break;

				default:

					cout << RED "SELECCIONE UNA OPCION VALIDA\n\n" RESET;
					system("pause");
					system("cls");


					break;
				}
			}

			break;

		case 2://MANTENIMIENTO

			maintenanceFlag = true;

			while (maintenanceFlag)
			{

				cout << TURQUOISE " * ** ** ** " BLUE "SUBMENU" TURQUOISE " ** ** ** *\n";
				cout << "*" LIGHT_PURPLE " 1) AGREGAR PELICULA" TURQUOISE "         *\n";
				cout << "*" LIGHT_PURPLE " 2) AGREGAR SALAS            " TURQUOISE "*\n";
				cout << "*" LIGHT_PURPLE " 3) AGREGAR HORARIOS         " TURQUOISE "*\n";
				cout << "*" PINK " 4) Volver al menu principal " TURQUOISE "*\n";
				cout << TURQUOISE " * ** ** ** ** ** ** ** ** * *\n\n" RESET;
				cout << "Seleccione una opcion: ";
				cin >> userChoice3;
				cout << endl << endl;
				system("cls");

				switch (userChoice3)
				{
				case 1:

					movie1.saveMovies();

					break;

				case 2:

					if (movieCount > 0) {
						Room1.saveRoomInformation(rooms);
					}
					else {
						cout << RED "NO HAY PELICULAS DISPONIBLES. AGREGUE PELICULAS ANTES DE ASIGNARLAS A LAS SALAS.\n" RESET;
						system("pause");
						system("cls");
					}

					break;

				case 3:

					if (movieCount > 0) {
						schedule1.saveDatesInformation(schedules);
					}
					else {
						cout << RED "NO HAY PELICULAS DISPONIBLES. AGREGUE PELICULAS ANTES DE ASIGNARLAS LOS HORARIOS.\n" RESET;
						system("pause");
						system("cls");
					}

					break;

				case 4:

					maintenanceFlag = false;

					break;

				default:

					cout << RED "SELECCIONE UNA OPCION VALIDA\n" RESET;
					system("pause");
					system("cls");
					break;
				}
			}
			break;

		case 3://RESERVA

			reserveFlag = true;

			while (reserveFlag)
			{
				cout << TURQUOISE " * ** ** ** " BLUE "SUBMENU" TURQUOISE " ** ** ** *\n";
				cout << "*" LIGHT_PURPLE " 1) VER CATALOGO" TURQUOISE "             *\n";
				cout << "*" LIGHT_PURPLE " 2) RESERVAR                 " TURQUOISE "*\n";
				cout << "*" PINK " 3) Volver al menu principal " TURQUOISE "*\n";
				cout << TURQUOISE " * ** ** ** ** ** ** ** ** * *\n\n" RESET;
				cout << "Seleccione una opcion: ";
				cin >> userChoice4;
				cout << endl << endl;
				system("cls");

				switch (userChoice4)
				{
				case 1:

					if (movieCount > 0) {
						cout << TURQUOISE "PE" << CYAN "LI" << PINK "CU" << GREEN "LAS\n" RESET;
						movie1.displayMovies();
						reserves.showAllInformation(schedules, rooms);
					}
					else {
						cout << RED "\nNO HAY PELICULAS DISPONIBLES.\n" RESET;
						system("pause");
						system("cls");
					}

					break;

				case 2:

					if (movieCount > 0) {
						reserves.saveReservationInformation(schedules, rooms);
					}
					else {
						cout << RED "\nNO HAY PELICULAS DISPONIBLES.\n" RESET;
						system("pause");
						system("cls");
					}

					break;

				case 3:

					reserveFlag = false;

					break;

				default:

					cout << RED "SELECCIONE UNA OPCION VALIDA\n" RESET;
					system("pause");
					system("cls");
					break;
				}
			}

			break;

		case 4://VENTA

			reserves.showReservations();
			sales.processPayment(reserves);

			break;

		default:

			cout << RED "SELECCIONE UNA OPCION VALIDA\n" RESET;
			system("pause");
			system("cls");

			break;
		}
	}

	delete[] rooms;

	return 0;
}