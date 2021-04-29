#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<time.h> 
#include<conio.h> 
#include<stdlib.h>
#pragma warning(disable:4996)


typedef struct hospital {
	char name[40];
	char city[10];
	char mantage[10];
	char adress[100];
}hospital;    



typedef struct mordeha {
	char firstname[15];
	char lastname[15];
	char nationalcode[15];
}mordeha;

typedef struct tarikh {
	int secc;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	int rahgiri;
	int tedad;
	int kol;
	int code;
	int u;
	int shomareh;
	char datee[50];
	char rooz[30];
	char name[40];
	char lastname[40];
	char nationalcode[40];

}tarikh;

typedef struct karbareadii {
	char lastname[15];
	char firstnamee[15];
	char nationalcode[15];
	char username[15];
	char password1[15];
	char email[40];
	char bloodtype[15];
	char age[15];
	char city[15];
	char mantage[15];
	char height[15];
	char weight[15];
	int mordeh;
	char vaziatsalamati[15];
	char dateofcode4[40];
	int codebimarivoroodi;
	int tedmolagati;
	int tedtestha;
	int tedmakanha;
	int rehgiri;
	int tedad;
	int kol;
	int code;
	int number;
	int dateoflastcode;
	char rooz[15];
	char vaziat[10];
	tarikh makanha[40];
	tarikh molaqat[40];
	tarikh testha[40];
}karbareadii;
typedef struct admin {
	char usernameadmin[15];
	char emailadmin[15];
	char passwordadmin[15];
	char natinalcodeadmin[15];
}admin;

typedef struct sahebshogl {
	char firstnameshopowner[15];
	char lastnameshopowner[15];
	char nationalcodeshopowner[15];
	char usernameshopowner[15];
	char passwordshopowner[15];
	char passwordbikhodi[15];
	char ShopName[15];
	char CityLocationShop[15];
	char Shoplocationarea[15];
	char  emailshopowner[30];
	char vaziatmakan[15];
	int vaziat;
	int rehgiri;
	int zedofooni;
	int tedad;
	int zamanaloodeh;
	int fardaloodeh;
	char rooz[15];
	tarikh moraje[100];
}sahebshogl;

FILE* file = NULL;

struct admin admin;
struct hospital hospital[40];
struct karbareadii karbareadii[100];
struct sahebshogl sahebshogl[100];
struct mordeha mordeha[100];
int tedkarbar;
int tedsahebshogl;
int tedhospital;
int tedmordeha;
int count;
int b;
int j;
char macan[10];

void voroodbebarnameh() {
	file = fopen("file.bin", "a+b");
	fseek(file, 0, SEEK_SET);
	fread(&tedkarbar, sizeof(int), 1, file);
	fread(&tedsahebshogl, sizeof(int), 1, file);
	fread(&tedhospital, sizeof(int), 1, file);
	fread(&tedmordeha, sizeof(int), 1, file);
	fread(&admin, sizeof(admin), 1, file);
	for (int m = 1; m < tedkarbar; m++)
	{
		fread(&karbareadii[m], sizeof(karbareadii), 1, file);
	}
	for (int m = 1; m < tedsahebshogl; m++)
	{
		fread(&sahebshogl[m], sizeof(sahebshogl), 1, file);
	}
	for (int m = 1; m < tedhospital; m++)
	{
		fread(&hospital[m], sizeof(hospital), 1, file);
	}
	for (int m = 1; m < tedmordeha; m++)
	{
		fread(&mordeha[m], sizeof(mordeha), 1, file);
	}

	fclose(file);
	return;

}
void Exit() {
	file = fopen("file.bin", "wb");
	fwrite(&tedkarbar, sizeof(tedkarbar), 1, file);
	fwrite(&tedsahebshogl, sizeof(tedsahebshogl), 1, file);
	fwrite(&tedhospital, sizeof(tedsahebshogl), 1, file);
	fwrite(&tedmordeha, sizeof(tedsahebshogl), 1, file);
	fwrite(&admin, sizeof(admin), 1, file);
	for (int m = 1; m < tedkarbar; m++)
	{
		if (karbareadii[m].mordeh == 0)
		{
			fwrite(&karbareadii[m], sizeof(karbareadii), 1, file);
		}
	}
	for (int m = 1; m < tedsahebshogl; m++)
	{
		fwrite(&sahebshogl[m], sizeof(sahebshogl), 1, file);
	}
	for (int m = 1; m < tedhospital; m++)
	{
		fwrite(&hospital[m], sizeof(hospital), 1, file);
	}
	for (int m = 1; m < tedmordeha; m++)
	{
		fwrite(&mordeha[m], sizeof(mordeha), 1, file);
	}
	fclose(file);
	exit(0);
}


int main() {

	char d[25];
	int tekrar = 1;
	char a;

	int gashtan = 0;
	int noeaccount;
	int menukarbar;
	char ch;
	int p;
	int m;
	int sorfeh;

	int tab;
	int tanginafas;
	int dard;
	int geloodard;
	int darsadbimari = 0;
	char menuforooshandeh[40];
	int editprofile;
	char  q = ' ';
	static char vaziatmakanshopowner[15] = { "red" };
	int zedofoonishopowner;
	static char vaziatmakansahebshogl[15] = { "red" };
	int zedofoonisahebshogl;
	char menuadmin[40];
	int numberinfectedplace;
	int dateofinfection = 0;
	char lastname[15];
	char firstname[15];
	char nationalcode[15];
	char username[15];
	char password1[15];
	char password2[15];
	char email[40];
	char bloodtype[15];
	char age[15];
	char height[15];
	char weight[15];
	char firstnameshopowner[15];
	char lastnameshopowner[15];
	char nationalcodeshopowner[15];
	char usernameshopowner[15];
	char passwordshopowner[15];
	char passwordbikhodi[15];
	char ShopName[15];
	char CityLocationShop[15];
	char Shoplocationarea[15];
	char  emailshopowner[30];
	char emailfaramooshi[15];
	char usernamefaramooshi[15];
	char nationalcodefaramooshi[15];
	char emailadmin[15] = { "@admin" };
	char usernameadmin[15] = { "admin" };
	char passwordadmin[15] = { "4321" };
	char natinalcodeadmin[15] = { "4321" };
	char firstnamesahebshogl[15] = { "fs" };
	char lastnamesahebshogl[15] = { "ls" };
	char citylocationsahebshogl[15] = { "cl" };
	char locationareasahebshogl[15] = { "la" };
	char shopnamesahebshogl[15] = { "laa" };
	char emailsahebshogl[15] = { "@sahebshogl" };
	char usernamesahebshogl[15] = { "sahebshogl" };
	char passwordsahebshogl[15] = { "1111" };
	char nationalcodesahebshogl[15] = { "1111" };
	char firstnamepishfarz[15] = { "ali" };
	char lastnamepishfarz[15] = { "matinkhah" };
	char emailpishfarz[15] = { "@karbareadi" };
	char usernamepishfarz[15] = { "karbareadi" };
	char passwordpishfarz[15] = { "1234" };
	char natinalcodepishfarz[15] = { "1234" };
	int codebimaripishfarz = 1;
	int codebimarivoroodi = 1;
	int sabtemolaghat = 0;
	char natinalcodemet[15];
	char usernamevoroodi[15];
	char passwordvoroodi[15];
	char nameplacemet[20];
	int accounttypevoroodi;
	const int timee = 400;
	int shomarehkarbar;
	int codesalamati;

	int year;
	int month;
	int day;
	int i;
	int fd = 1;
	int gh = 1;
	/*struct admin admin { "alireza", "@alireza", "1234", "1234" };
	file = fopen("file.bin", "w+b");
	fwrite(&gh, sizeof(int), 1, file);
	fwrite(&fd, sizeof(int), 1, file);
	fwrite(&fd, sizeof(int), 1, file);
	fwrite(&fd, sizeof(int), 1, file);
	fwrite(&admin, sizeof(admin), 1, file);
	fclose(file);*/


	system("color 80");
	for (int c = 0; c <= 7; c++) {
		if (c == 0)
			printf("                  888    d8b                            d8b      888       \n");
		else if (c == 1)
			printf("                  888    Y8P                            Y8P      888       \n");
		else if (c == 2)
			printf("                  888                                            888       \n");
		else if (c == 3)
			printf(" 8888b.  88888b.  888888 888  .d8888b  .d88b.  888  888 888  .d88888       \n");
		else if (c == 4)
			printf("     88b 888  88b 888    888 d88P     d88  88b 888  888 888 d88  888       \n");
		else if (c == 5)
			printf(".d888888 888  888 888    888 888      888  888 Y88  88P 888 888  888       \n");
		else if (c == 6)
			printf("888  888 888  888 Y88b.  888 Y88b.    Y88..88P  Y8bd8P  888 Y88b 888       \n");
		else if (c == 7)
			printf(" Y888888 888  888   Y888 888   Y8888P   Y88P     Y88P   888   Y88888       \n");
		Sleep(timee);
		fflush(stdout);
	}



	a = getchar();
	system("cls");
	printf("                           #popular action against corona\n\n\n\n\n");
	voroodbebarnameh();
	while (1)
	{
		system("color 20");
		int peida = 0;
		for (int c = 0; c <= 3; c++) {
			if (c == 0)
				printf("1-Login to the program\n\n");
			else if (c == 1)
				printf("2-create new account\n\n");
			else if (c == 2)
				printf("3-forget password\n\n");
			else if (c == 3)
				printf("4-Exit the app\n");
			Sleep(timee);
			fflush(stdout);
		}
		time_t noww;
		noww = time(NULL);

		for (int lo = 1; lo < tedkarbar; lo++) {
			if ((karbareadii[lo].codebimarivoroodi > 1) && (karbareadii[lo].codebimarivoroodi != 4) && ((difftime(noww, karbareadii[lo].dateoflastcode) > 604800)))
			{
				karbareadii[lo].dateoflastcode = noww;
				karbareadii[lo].codebimarivoroodi--;
			}
		}
		for (int lo = 1; lo < tedkarbar; lo++)
		{
			if (karbareadii[lo].codebimarivoroodi == 4)
			{
				for (int ke = 0; ke < karbareadii[lo].tedmolagati; ke++)
				{
					if ((karbareadii[karbareadii[lo].molaqat[ke].tedad].codebimarivoroodi != 4) && (difftime(karbareadii[lo].molaqat[ke].day, noww) < 604800))
						karbareadii[karbareadii[lo].molaqat[ke].tedad].codebimarivoroodi = 3;
				}
			}
		}
		for (int lo = 1; lo < tedkarbar; lo++) {
			if ((difftime(noww, sahebshogl[lo].zamanaloodeh) > 129600))
			{
				strcpy(sahebshogl[lo].vaziatmakan, "White");
			}
		}
		for (int lo = 1; lo < tedkarbar; lo++) {
			if (karbareadii[lo].codebimarivoroodi == 4)
			{
				for (int ke = 0; ke < karbareadii[lo].tedmakanha; ke++) {
					if ((difftime(noww, karbareadii[lo].makanha[ke].day) < 604800) && (sahebshogl[lo].zedofooni == 0))
						strcpy(sahebshogl[karbareadii[lo].makanha[ke].shomareh].vaziatmakan, "Red");
				}
			}
		}

		gets_s(d);
		if ((strcmp(d, "4") == 0) || (strcmp(d, "Exit the app") == 0))
		{
			Exit();
			return 0;
		}

		if ((!strcmp(d, "Login to the program")) || (!strcmp(d, "1")))
		{
			system("cls");
			system("color 50");
			printf("username:");
			gets_s(usernamevoroodi);
			printf("\n\npassword:");

			int count = 0;
			while (1) {
				passwordvoroodi[count] = getch();
				if (passwordvoroodi[count] == '\b' && count > 0) {
					printf("\b \b");
					count--;
				}
				else if (passwordvoroodi[count] != '\r') {
					printf("*");
					count++;
				}
				else if (passwordvoroodi[count] == '\r') {
					count++;
					break;
				}
			}
			passwordvoroodi[count - 1] = '\0';

			printf("\n\nAccount type(1-admin   2-normaluser    3-shop owner):");
			scanf("%d", &accounttypevoroodi);

			if ((accounttypevoroodi == 1) && (strcmp(usernamevoroodi, admin.usernameadmin) == 0) && (strcmp(passwordvoroodi, admin.passwordadmin) == 0))
			{

				while (1) {
					system("cls");
					printf("\n\n1-new hospital");
					printf("\n\n2-view satistics");
					printf("\n\n3-improved people");
					printf("\n\n4-all app users");
					printf("\n\n5-dead people");
					printf("\n\n6-registered businesses");
					printf("\n\n7-registered hospital");
					printf("\n\n8-go to main menu");
					printf("\n\n9-exit the app");
					gets_s(menuadmin);
					if (strcmp(menuadmin, "1") == 0 || strcmp(menuadmin, "new hospital") == 0)
					{
						system("cls");
						printf("name of hospital:");
						gets_s(hospital[tedhospital].name);
						printf("city of hospital:");
						gets_s(hospital[tedhospital].city);
						printf("region of hospital:");
						gets_s(hospital[tedhospital].mantage);
						printf("address of hospital:");
						gets_s(hospital[tedhospital].adress);

						printf("new hospital has been successfully registered...... ");
						tedhospital++;
						getchar();
						continue;
					}
					if (strcmp(menuadmin, "3") == 0 || strcmp(menuadmin, "improved people") == 0)
					{
						char nationalcodeimproved[20];
						int koodoom;
						system("cls");
						printf("which one:\n\n\n");
						printf("1-improved people\n\n2-dead people");
						scanf("%d", &koodoom);
						if (koodoom == 1)
						{
							system("cls");
							printf("please enter nationalcode:");
							getchar();
							gets_s(nationalcodeimproved);
							int peidaa = 0;
							for (int lo = 1; lo < tedkarbar; lo++) {
								if (strcmp(nationalcodeimproved, karbareadii[lo].nationalcode) == 0)
								{
									printf("the desired user was found");
									peida = 1;
									if (karbareadii[lo].codebimarivoroodi == 4)
										karbareadii[lo].codebimarivoroodi = 2;
									getchar();
									system("cls");
									continue;
								}
							}
							if (peida == 0) {
								printf("the user was not found");
								getchar();
								system("cls");
								continue;
							}

						}
						if (koodoom == 2)
						{
							system("cls");
							printf("please enter nationalcode:");
							getchar();
							gets_s(nationalcodeimproved);
							int peidaa = 0;
							for (int lo = 1; lo < tedkarbar; lo++) {
								if (strcmp(nationalcodeimproved, karbareadii[lo].nationalcode) == 0)
								{

									strcpy((mordeha[tedmordeha].firstname), (karbareadii[lo].firstnamee));
									strcpy((mordeha[tedmordeha].lastname), (karbareadii[lo].lastname));
									strcpy((mordeha[tedmordeha].nationalcode), (karbareadii[lo].nationalcode));
									tedkarbar--;
									tedmordeha++;
									karbareadii[lo].mordeh = 1;
									printf("the desired user was found");
									peidaa = 1;
									getchar();
									system("cls");;
									continue;
								}
							}
							if (peidaa == 0) {
								printf("the user was not found");
								getchar();
								system("cls");;
								continue;
							}
						}
						continue;
					}
					if (strcmp(menuadmin, "5") == 0 || strcmp(menuadmin, "dead people") == 0)
					{
						system("cls");
						for (int lo = 1; lo < tedmordeha; lo++)
							printf("\n\nfirst name:%s\nlast name:%s\nnational code:%s", &mordeha[lo].firstname, &mordeha[lo].lastname, &mordeha[lo].nationalcode);
						getchar();
						continue;
					}
					if (strcmp(menuadmin, "4") == 0 || strcmp(menuadmin, "all app users") == 0)
					{
						system("cls");
						for (int lo = 1; lo < tedkarbar; lo++)
						{
							if (karbareadii[lo].mordeh == 0)
							{
								printf("firstname:%s\nlastname:%s\nnationalcode:%s\nhealth status:%d", karbareadii[lo].firstnamee, karbareadii[lo].lastname, karbareadii[lo].nationalcode, karbareadii[lo].codebimarivoroodi);
								printf("\n\n\n");
							}
						}
						for (int lo = 1; lo < tedsahebshogl; lo++)
						{

							printf("firstname:%s\nlastname:%s\nnationalcode:%s\nsahebshogl", sahebshogl[lo].firstnameshopowner, sahebshogl[lo].lastnameshopowner, sahebshogl[lo].nationalcodeshopowner);
							printf("\n\n\n");
						}
						getchar();
						continue;
					}
					if (strcmp(menuadmin, "2") == 0 || strcmp(menuadmin, "view satistics") == 0)
					{
						system("cls");
						for (int lo = 1; lo < tedkarbar; lo++)
						{
							if ((karbareadii[lo].codebimarivoroodi) == 4)
								printf("firstname:%s\nlastname:%s\nnationalcode:%s\ndate of infection:%s", karbareadii[lo].firstnamee, karbareadii[lo].lastname, karbareadii[lo].nationalcode, karbareadii[lo].dateofcode4);
						}
						getchar();
						continue;
					}
					if (strcmp(menuadmin, "7") == 0 || strcmp(menuadmin, "registered hospital") == 0)
					{
						system("cls");
						for (int lo = 1; lo < tedhospital; lo++)
						{
							printf("name:%s\ncity:%s\nregion:%s\naddress:%s", hospital[lo].name, hospital[lo].city, hospital[lo].mantage, hospital[lo].adress);
							printf("\n\n\n");
						}
						getchar();
						system("cls");
						continue;
					}
					if (strcmp(menuadmin, "9") == 0 || strcmp(menuadmin, "exit the app") == 0)
					{
						Exit();
						return 0;
					}
					if (strcmp(menuadmin, "6") == 0 || strcmp(menuadmin, "registered businesses") == 0)
					{
						system("cls");
						for (int lo = 1; lo < tedsahebshogl; lo++)
						{
							printf("national code(shopowner):%s\nshop name:%s\nshop status:%s\n", sahebshogl[lo].nationalcodeshopowner, sahebshogl[lo].ShopName, sahebshogl[lo].vaziatmakan);
							printf("\n\n\n");
						}
						getchar();
						continue;
					}
					if (strcmp(menuadmin, "8") == 0 || strcmp(menuadmin, "go to main menu") == 0)
					{
						system("cls");
						break;
					}
				}
			}

			else if (accounttypevoroodi == 3)

			{
				for (int lo = 1; lo < tedsahebshogl; lo++)
				{
					if ((strcmp(usernamevoroodi, sahebshogl[lo].usernameshopowner) == 0) && (strcmp(sahebshogl[lo].passwordshopowner, passwordvoroodi) == 0))
					{
						peida = 1;
						shomarehkarbar = lo;
						break;
					}
				}
				if (peida == 0)
				{
					system("cls");
					printf("no user with this profile was found.... ");
					getchar();
					getchar();
					system("cls");
					continue;
				}
				while (peida) {
					system("cls");
					printf("\n\n1-location status");
					printf("\n\n2-notify for disinfection");
					printf("\n\n3-edit profile");
					printf("\n\n4-number of infected people in this place");
					printf("\n\n5-go to main menu");
					printf("\n\n6-Exit the app");
					gets_s(menuforooshandeh);
					if (strcmp(menuforooshandeh, "6") == 0 || strcmp(menuforooshandeh, "Exit the app") == 0)
					{
						Exit();
						return 0;
					}
					if (strcmp(menuforooshandeh, "1") == 0 || strcmp(menuforooshandeh, "location status") == 0)
					{
						system("cls");
						printf("\n\nlocation status:%s", sahebshogl[shomarehkarbar].vaziatmakan);
						getchar();
						getchar();
						system("cls");
						continue;


					}
					if ((strcmp(menuforooshandeh, "4") == 0) || strcmp(menuforooshandeh, "number of infected people in this place") == 0)
					{
						system("cls");
						int peidaa = 0;
						printf("firstname               lastname              healthstatus\n");
						for (int lo = 0; lo < tedkarbar; lo++) {
							for (int ke = 0; ke < tedsahebshogl; ke++)
							{
								if (strcmp(sahebshogl[shomarehkarbar].ShopName, karbareadii[lo].makanha[ke].name) == 0)
								{
									printf("%s                      %s                     %d\n\n", karbareadii[lo].firstnamee, karbareadii[lo].lastname, karbareadii[lo].codebimarivoroodi);
									peidaa = 1;
								}
							}
						}
						if (peidaa == 0) {
							system("cls");
							printf("no infected person came to this place");
						}
						getchar();
						continue;

					}
					if (strcmp(menuforooshandeh, "2") == 0 || strcmp(menuforooshandeh, "notify for disinfection") == 0)
					{
						system("cls");
						printf("\n\nhave you disinfected your place?\n1-yes    2-no");
						scanf("%d", &sahebshogl[shomarehkarbar].zedofooni);

						if (sahebshogl[shomarehkarbar].zedofooni == 1) {
							strcpy(sahebshogl[shomarehkarbar].vaziatmakan, "white");
							system("cls");
							printf("\n\ndisinfection was performed successfully");
							getchar();
							getchar();
							system("cls");
							continue;

						}
						if (sahebshogl[shomarehkarbar].zedofooni == 2)
						{
							system("cls");
							continue;
						}
					}
					if (strcmp(menuforooshandeh, "3") == 0 || strcmp(menuforooshandeh, "edit profile") == 0)
					{
						system("cls");
						printf("\n\nWhich information do you want to change?\n\n");
						printf("\n\n1-first name\n\n");
						printf("\n\n2-last name\n\n");
						printf("\n\n3-national code\n\n");
						printf("\n\n4-user name\n\n");
						printf("\n\n5-email\n\n");
						printf("\n\n6-shop name\n\n");
						printf("\n\n7-city location shop\n\n");
						printf("\n\n8-shop licationarea\n\n");
						scanf("%d", &editprofile);
						getchar();
						system("cls");
						if (editprofile == 1)
						{
							printf("\n\nfirst name:\n\n");
							gets_s(sahebshogl[shomarehkarbar].firstnameshopowner);
							continue;
						}
						if (editprofile == 2)
						{
							printf("\n\nlast name:\n\n");
							gets_s(sahebshogl[shomarehkarbar].lastnameshopowner);
							continue;
						}
						if (editprofile == 3)
						{
							printf("\n\nnationalcode:\n\n");
							gets_s(sahebshogl[shomarehkarbar].nationalcodeshopowner);
							continue;
						}
						if (editprofile == 4)
						{
							printf("\n\nuser name:\n\n");
							gets_s(sahebshogl[shomarehkarbar].usernameshopowner);
							continue;
						}
						if (editprofile == 5)
						{
							printf("\n\nemail:\n\n");
							gets_s(sahebshogl[shomarehkarbar].emailshopowner);
							continue;
						}
						if (editprofile == 6)
						{
							printf("\n\nshop name:\n\n");
							gets_s(sahebshogl[shomarehkarbar].ShopName);
							continue;
						}
						if (editprofile == 7)
						{
							printf("\n\ncity location shop:\n\n");
							gets_s(sahebshogl[shomarehkarbar].CityLocationShop);
							continue;
						}
						if (editprofile == 8)
						{
							printf("\n\nshop location area:\n\n");
							gets_s(sahebshogl[shomarehkarbar].Shoplocationarea);
							continue;
						}



					}
					if (!strcmp(menuforooshandeh, "5"))
					{
						system("cls");
						break;
					}
				}

				continue;
			}

			else if (accounttypevoroodi == 2)
			{

				for (int lo = 0; lo < tedkarbar; lo++)
				{

					if ((strcmp(usernamevoroodi, karbareadii[lo].username) == 0) && (strcmp(passwordvoroodi, karbareadii[lo].password1) == 0))
					{
						peida = 1;
						shomarehkarbar = lo;
						break;
					}
				}
				if (peida == 0)
				{
					system("cls");
					printf("no user with this profile was found.... ");
					getchar();
					getchar();
					system("cls");
					continue;
				}

				while (peida) {
					system("cls");
					printf("1-record the latest health status\n\n");
					printf("2-view the latest health status\n\n");
					printf("3-edit profile\n\n");
					printf("4-history of health status\n\n");
					printf("5-meeting appointment\n\n");
					printf("6-meeting history\n\n");
					printf("7-add missing places\n\n");
					printf("8-history of places gone\n\n");
					printf("9-corona statistics\n\n");
					printf("10-surrounding hospitals\n\n");
					printf("11-go to main menu\n\n");
					printf("12-Exit the app\n");
					scanf("%d", &menukarbar);
					if (menukarbar == 12) {
						Exit();
						return 0;
					}
					if (menukarbar == 1)
					{
						darsadbimari = 0;
						system("cls");
						printf("1-Dry cough:\n1-yes      2-no");
						scanf("%d", &sorfeh);
						printf("\n\n2-High fever:\n1-yes      2-no");
						scanf("%d", &tab);
						printf("\n\n3-Shortness of breath:\n1-yes      2-no");
						scanf("%d", &tanginafas);
						printf("\n\n4-Pain and bruising:\n1-yes      2-no");
						scanf("%d", &dard);
						printf("\n\n5-Sore throat:\n1-yes      2-no");
						scanf("%d", &geloodard);
						if (sorfeh == 1)
							darsadbimari = darsadbimari + 30;
						if (tab == 1)
							darsadbimari = darsadbimari + 20;
						if (tanginafas == 1)
							darsadbimari = darsadbimari + 20;
						if (dard == 1)
							darsadbimari = darsadbimari + 15;
						if (geloodard == 1)
							darsadbimari = darsadbimari + 15;
						time_t nowww;
						nowww = time(NULL);
						struct tm* tm = localtime(&nowww);
						karbareadii[shomarehkarbar].dateoflastcode = nowww;
						int tedtesthaa = karbareadii[shomarehkarbar].tedtestha;
						strcpy(karbareadii[shomarehkarbar].testha[tedtesthaa].datee, asctime(tm));

						system("cls");
						if (darsadbimari < 15)
						{
							codesalamati = 1;
							if ((!(karbareadii[shomarehkarbar].codebimarivoroodi == 2)) && (!(karbareadii[shomarehkarbar].codebimarivoroodi == 3)) && (!(karbareadii[shomarehkarbar].codebimarivoroodi == 4)))
							{
								int teddtestha = karbareadii[shomarehkarbar].tedtestha;
								karbareadii[shomarehkarbar].codebimarivoroodi = 1;
								(karbareadii[shomarehkarbar].testha[teddtestha].code = 1);
								(karbareadii[shomarehkarbar].tedtestha)++;
								printf("\n\n\nYou are healthy(code1)\n\n");
							}
						}
						else if (darsadbimari < 50)
						{
							codesalamati = 2;
							if ((!(karbareadii[shomarehkarbar].codebimarivoroodi == 4)) && (!(karbareadii[shomarehkarbar].codebimarivoroodi == 3)))
							{
								int teddtestha = karbareadii[shomarehkarbar].tedtestha;
								karbareadii[shomarehkarbar].codebimarivoroodi = 2;
								(karbareadii[shomarehkarbar].testha[teddtestha].code = 2);
								(karbareadii[shomarehkarbar].tedtestha)++;
								printf("\n\n\nYou are suspected of having the disease(code2)\n\n");
							}
						}
						else if (darsadbimari < 75)
						{
							codesalamati = 3;
							if (!(karbareadii[shomarehkarbar].codebimarivoroodi == 4))
							{
								int teddtestha = karbareadii[shomarehkarbar].tedtestha;
								karbareadii[shomarehkarbar].codebimarivoroodi = 3;
								(karbareadii[shomarehkarbar].testha[teddtestha].code = 3);
								(karbareadii[shomarehkarbar].tedtestha)++;
								printf("\n\n\nYou are dangerous(code3)\n\n");
							}
						}
						else if (darsadbimari < 101)
						{
							codesalamati = 4;

							int teddtestha = karbareadii[shomarehkarbar].tedtestha;
							time_t code4 = time(NULL);
							struct tm* codee4 = localtime(&code4);
							strcpy(karbareadii[shomarehkarbar].dateofcode4, asctime(codee4));
							(karbareadii[shomarehkarbar].testha[teddtestha].code = 4);
							karbareadii[shomarehkarbar].codebimarivoroodi = 4;
							(karbareadii[shomarehkarbar].tedtestha)++;
							printf("\n\n\nYou are sick(code4)\n\n");
						}
						getchar();
						getchar();
						system("cls");
						continue;

					}
					if (menukarbar == 9) {
						int f = 0;
						for (int lo = 0; lo < tedkarbar; lo++) {
							if (karbareadii[lo].codebimarivoroodi == 4)
								f++;
						}
						system("cls");
						printf("number of infected:%d", f);
						getchar();
						getchar();
						system("cls");
						continue;
					}
					if (menukarbar == 4) {
						system("cls");
						for (int lo = 0; lo < karbareadii[shomarehkarbar].tedtestha; lo++)
						{
							printf("\n\ndate:%s\nhealth status:%d", karbareadii[shomarehkarbar].testha[lo].datee, karbareadii[shomarehkarbar].testha[lo].code);
						}
						getchar();
						getchar();
						system("cls");
						continue;
					}
					if (menukarbar == 2)
					{
						if ((karbareadii[shomarehkarbar].codebimarivoroodi) == 1)
						{

							system("cls");
							printf("\n\n\nYou are healthy(code1)\n\n");
						}
						else if ((karbareadii[shomarehkarbar].codebimarivoroodi) == 2)
						{

							system("cls");
							printf("\n\n\nYou are suspected of having the disease(code2)\n\n");
						}
						else if ((karbareadii[shomarehkarbar].codebimarivoroodi) == 3)
						{

							system("cls");
							printf("\n\n\nYou are dangerous(code3)\n\n");
						}
						else if ((karbareadii[shomarehkarbar].codebimarivoroodi) == 4)
						{

							system("cls");
							printf("\n\n\nYou are sick(code4)\n\n");
						}
						getchar();
						getchar();
						system("cls");
						continue;
					}
					if (menukarbar == 11)
					{
						system("cls");
						getchar();
						break;
					}
					if (menukarbar == 10) {
						int peida = 0;
						system("cls");
						printf("city:");
						getchar();
						gets_s(karbareadii[shomarehkarbar].city);
						printf("\n\nregion:");
						gets_s(karbareadii[shomarehkarbar].mantage);
						system("cls");
						printf("hospitals around you : \n\n\n");
						for (int lo = 1; lo <= tedhospital; lo++) {
							if ((strcmp(hospital[lo].city, karbareadii[shomarehkarbar].city) == 0) && (strcmp(karbareadii[shomarehkarbar].mantage, hospital[lo].mantage) == 0))
							{
								printf("%d:name   %s    address:   %s ", lo, &hospital[lo].name, &hospital[lo].adress);
								printf("\n\n\n");
								peida = 1;

							}

						}
						if (peida == 0) {
							printf("\n\n        [:no hospital around you:]");
						}
						getchar();
						system("cls");
						continue;
					}
					if (menukarbar == 7) {
						system("cls");
						int peidaaa = 0;
						getchar();
						printf("the place name is gone:");
						gets_s(nameplacemet);
						for (int lo = 0; lo < tedsahebshogl; lo++)
						{
							if (strcmp(nameplacemet, sahebshogl[lo].ShopName) == 0)
							{
								peidaaa = 1;

								if (strcmp(sahebshogl[lo].vaziatmakan, "Red") == 0) {
									printf("you are sure to go to this place?\n\n");
									printf("1-yes\n");
									printf("2-no\n");
									int menuuu;
									scanf("%d", &menuuu);
									if (menuuu == 1)
									{
										if (karbareadii[shomarehkarbar].codebimarivoroodi == 4)
											strcpy(sahebshogl[lo].vaziatmakan, "Red");
										karbareadii[shomarehkarbar].tedmakanha++;
										int tedplace = karbareadii[shomarehkarbar].tedmakanha;
										if (karbareadii[shomarehkarbar].codebimarivoroodi == 1)
											karbareadii[shomarehkarbar].codebimarivoroodi = 2;
										time_t aloodehh;
										aloodehh = time(NULL);
										struct tm* aloodehhh = localtime(&aloodehh);
										sahebshogl[lo].zamanaloodeh = aloodehh;
										karbareadii[shomarehkarbar].makanha[tedplace].day = aloodehh;
										strcpy(karbareadii[shomarehkarbar].makanha[tedplace].datee, asctime(aloodehhh));
										sahebshogl[lo].fardaloodeh = shomarehkarbar;
										strcpy(karbareadii[shomarehkarbar].makanha[tedplace].name, sahebshogl[lo].ShopName);
										karbareadii[shomarehkarbar].makanha[tedplace].shomareh = lo;

									}

									if ((menuuu == 2))
										break;
								}
								else {

									int tedplace = karbareadii[shomarehkarbar].tedmakanha;
									time_t aloodehh;
									aloodehh = time(NULL);
									struct tm* aloodehhh = localtime(&aloodehh);
									sahebshogl[lo].zamanaloodeh = aloodehh;
									karbareadii[shomarehkarbar].makanha[tedplace].day = aloodehh;
									strcpy(karbareadii[shomarehkarbar].makanha[tedplace].datee, asctime(aloodehhh));
									sahebshogl[lo].fardaloodeh = shomarehkarbar;
									strcpy(karbareadii[shomarehkarbar].makanha[tedplace].name, sahebshogl[lo].ShopName);
									karbareadii[shomarehkarbar].makanha[tedplace].shomareh = lo;
									karbareadii[shomarehkarbar].tedmakanha++;
								}


								break;
							}
						}
						if (peidaaa == 0)
						{
							system("cls");
							printf("No users were found with this profile");
							getchar();
						}
						continue;

					}
					if (menukarbar == 5)
					{
						system("cls");
						int peidaaa = 0;
						getchar();
						printf("nationalcode of person met:");
						gets_s(natinalcodemet);

						for (int lo = 1; lo < tedkarbar; lo++) {
							if ((strcmp(karbareadii[lo].nationalcode, natinalcodemet) == 0)) {
								int tedmolagati = karbareadii[lo].tedmolagati;
								int tedmolagatii = karbareadii[shomarehkarbar].tedmolagati;
								karbareadii[lo].tedmolagati++;
								karbareadii[shomarehkarbar].tedmolagati++;
								strcpy(karbareadii[lo].molaqat[tedmolagati].name, karbareadii[shomarehkarbar].firstnamee);
								strcpy(karbareadii[shomarehkarbar].molaqat[tedmolagatii].name, karbareadii[lo].firstnamee);
								time_t tim;
								tim = time(NULL);
								struct tm* tmm = localtime(&tim);
								karbareadii[shomarehkarbar].molaqat[tedmolagatii].day == tim;
								karbareadii[lo].molaqat[tedmolagatii].day == tim;
								karbareadii[lo].molaqat[tedmolagatii].tedad = shomarehkarbar;
								karbareadii[shomarehkarbar].molaqat[tedmolagatii].tedad = lo;
								strcpy(karbareadii[shomarehkarbar].molaqat[tedmolagatii].datee, asctime(tmm));
								strcpy(karbareadii[lo].molaqat[tedmolagati].datee, asctime(tmm));
								karbareadii[lo].molaqat[tedmolagati].shomareh = shomarehkarbar;
								karbareadii[shomarehkarbar].molaqat[tedmolagati].shomareh = lo;
								peidaaa = 1;
								printf("The requested user was found successfully");
								getchar();
								break;
							}
						}
						if (peidaaa == 0) {
							printf("\n\n no user with this profile was found....");
							getchar();
						}

						continue;
					}
					if (menukarbar == 6) {
						system("cls");
						for (int lo = 0; lo < karbareadii[shomarehkarbar].tedmolagati; lo++)
						{
							int n = karbareadii[shomarehkarbar].molaqat[lo].shomareh;
							printf("\n\nname:%s\ndate:%s\nhealth status:%d", karbareadii[shomarehkarbar].molaqat[lo].name, karbareadii[shomarehkarbar].molaqat[lo].datee, karbareadii[n].codebimarivoroodi);
						}
						getchar();
						getchar();
						continue;
					}
					if (menukarbar == 3)
					{

						system("cls");
						printf("\n\nWhich information do you want to change?\n\n");
						printf("\n\n1-first name\n\n");
						printf("\n\n2-last name\n\n");
						printf("\n\n3-national code\n\n");
						printf("\n\n4-user name\n\n");
						printf("\n\n5-email\n\n");
						printf("\n\n6-blood type\n\n");
						printf("\n\n7-age\n\n");
						printf("\n\n8-height\n\n");
						printf("\n\n9-weight\n\n");
						scanf("%d", &editprofile);
						getchar();
						system("cls");
						if (editprofile == 1)
						{
							printf("\n\nfirst name:\n\n");
							gets_s(karbareadii[shomarehkarbar].firstnamee);
							continue;
						}
						if (editprofile == 2)
						{
							printf("\n\nlast name:\n\n");
							gets_s(karbareadii[shomarehkarbar].lastname);
							continue;
						}
						if (editprofile == 3)
						{
							printf("\n\nnationalcode:\n\n");
							gets_s(karbareadii[shomarehkarbar].nationalcode);
							continue;
						}
						if (editprofile == 4)
						{
							printf("\n\nuser name:\n\n");
							gets_s(karbareadii[shomarehkarbar].username);
							continue;
						}
						if (editprofile == 5)
						{
							printf("\n\nemail:\n\n");
							gets_s(karbareadii[shomarehkarbar].email);
							continue;
						}
						if (editprofile == 6)
						{
							printf("\n\nblood type:\n\n");
							gets_s(karbareadii[shomarehkarbar].bloodtype);
							continue;
						}
						if (editprofile == 7)
						{
							printf("\n\nage:\n\n");
							gets_s(karbareadii[shomarehkarbar].age);
							continue;
						}
						if (editprofile == 8)
						{
							printf("\n\nheight:\n\n");
							gets_s(karbareadii[shomarehkarbar].height);
							continue;
						}
						if (editprofile == 9)
						{
							printf("\n\nweight:\n\n");
							gets_s(karbareadii[shomarehkarbar].weight);
							continue;
						}

					}
					if (menukarbar == 8) {
						system("cls");
						for (int lo = 0; lo < karbareadii[shomarehkarbar].tedmakanha; lo++)
						{
							int n = karbareadii[shomarehkarbar].makanha[lo].shomareh;
							printf("\n\nname:%s\ndate:%s\nhealth status(place):%s", karbareadii[shomarehkarbar].makanha[lo].name, karbareadii[shomarehkarbar].makanha[lo].datee, sahebshogl[n].vaziatmakan);
						}
						getchar();
						getchar();
						continue;
					}

				}

			}
			else {

				system("cls");
				printf("no user with this profile was found.... ");
				getchar();
				getchar();
				system("cls");
				continue;
			}
			continue;

		}


		if ((!strcmp(d, "2")) || (!strcmp(d, "creat new account")))
		{
			system("cls");
			system("color 70");
			printf("What kind of account do you want to create?\n\n\n\n\n1-normal user\n\n2-Business owner\n");
			scanf("%d", &noeaccount);
			system("cls");
			if (noeaccount == 1)
			{

				getchar();
				int ok = 0;
				do {
					printf("first name:");

					gets_s(karbareadii[tedkarbar].firstnamee);
					if (strlen(karbareadii[tedkarbar].firstnamee) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);

				printf("\n^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~ ^_~\n\n");

				ok = 0;
				do {
					printf("last name:");
					gets_s(karbareadii[tedkarbar].lastname);
					if (strlen(karbareadii[tedkarbar].lastname) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\n:-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-) :-)\n\n");
				ok = 0;
				do {
					printf("national code:");
					gets_s(karbareadii[tedkarbar].nationalcode);
					if (strlen(karbareadii[tedkarbar].nationalcode) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\n:-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D :-D \n\n");
				ok = 0;
				do {
					printf("user name:");
					gets_s(karbareadii[tedkarbar].username);
					if (strlen(karbareadii[tedkarbar].username) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\n>_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< >_< \n\n");
				while (1) {
					printf("password:");
					int count = 0;
					while (1) {
						password1[count] = getch();
						if (password1[count] == '\b' && count > 0) {
							printf("\b \b");
							count--;
						}
						else if (password1[count] != '\r') {
							printf("*");
							count++;
						}
						else if (password1[count] == '\r') {
							count++;
							break;
						}
					}
					password1[count - 1] = '\0';
					printf("\n");
					printf("password(repetition):");

					count = 0;
					while (1) {
						password2[count] = getch();
						if (password2[count] == '\b' && count > 0) {
							printf("\b \b");
							count--;
						}
						else if (password2[count] != '\r') {
							printf("*");
							count++;
						}
						else if (password2[count] == '\r') {
							count++;
							break;
						}
					}
					password2[count - 1] = '\0';
					printf("\n");
					if (strcmp(password1, password2) == 0)
					{

						strcpy(karbareadii[tedkarbar].password1, password1);
						break;
					}
					if (strcmp(password1, password2) != 0)
						printf("\nEROR,The password and its repetition are not the same\n\n");
				}
				printf("\n:D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D :D \n\n");
				ok = 0;
				do {
					printf("email:");
					gets_s(karbareadii[tedkarbar].email);
					if (strlen(karbareadii[tedkarbar].email) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\nO.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O O.O  \n\n");
				printf("blood type:");
				gets_s(karbareadii[tedkarbar].bloodtype);
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");
				printf("age:");
				gets_s(karbareadii[tedkarbar].age);
				printf("\nU_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U U_U  \n\n");
				printf("height:");
				gets_s(karbareadii[tedkarbar].height);
				printf("\n:-() :-() :-() :-() :-() :-() :-() :-() :-() :-() :-() :-() :-() :-() :-() :-()  \n\n");
				printf("weight:");
				gets_s(karbareadii[tedkarbar].weight);
				tedkarbar++;
			}


			if (noeaccount == 2)
			{

				getchar();
				int ok = 0;
				do {
					printf("first name(shop owner):");

					gets_s(sahebshogl[tedsahebshogl].firstnameshopowner);
					if (strlen(sahebshogl[tedsahebshogl].firstnameshopowner) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");
				ok = 0;
				do {
					printf("last name(shop owner):");

					gets_s(sahebshogl[tedsahebshogl].lastnameshopowner);
					if (strlen(sahebshogl[tedsahebshogl].lastnameshopowner) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");
				ok = 0;
				do {
					printf("national code(shop owner):");

					gets_s(sahebshogl[tedsahebshogl].nationalcodeshopowner);
					if (strlen(sahebshogl[tedsahebshogl].nationalcodeshopowner) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");
				ok = 0;
				do {
					printf("user name(shop owner):");

					gets_s(sahebshogl[tedsahebshogl].usernameshopowner);
					if (strlen(sahebshogl[tedsahebshogl].usernameshopowner) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");

				while (1) {
					printf("password(shop owner):");
					int count = 0;
					while (1) {
						password1[count] = getch();
						if (password1[count] == '\b' && count > 0) {
							printf("\b \b");
							count--;
						}
						else if (password1[count] != '\r') {
							printf("*");
							count++;
						}
						else if (password1[count] == '\r') {
							count++;
							break;
						}
					}
					(password1)[count - 1] = '\0';
					printf("\n");
					printf("password(repetition):");

					count = 0;
					while (1) {
						password2[count] = getch();
						if (password2[count] == '\b' && count > 0) {
							printf("\b \b");
							count--;
						}
						else if (password2[count] != '\r') {
							printf("*");
							count++;
						}
						else if (password2[count] == '\r') {
							count++;
							break;
						}
					}
					password2[count - 1] = '\0';
					printf("\n");
					if (strcmp(password1, password2) == 0)
					{

						strcpy((sahebshogl[tedsahebshogl].passwordshopowner), password1);
						break;
					}
					if (strcmp(password1, password2) != 0)
						printf("\nEROR,The password and its repetition are not the same\n\n");
				}
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");
				ok = 0;
				do {
					printf("email shopowner:");

					gets_s(sahebshogl[tedsahebshogl].emailshopowner);
					if (strlen(sahebshogl[tedsahebshogl].emailshopowner) < 1)
						ok = 0;
					else
						ok = 1;
				} while (!ok);
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");
				printf("Shop Name:");
				gets_s(sahebshogl[tedsahebshogl].ShopName);
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");
				printf("City Location Shop:");
				gets_s(sahebshogl[tedsahebshogl].CityLocationShop);
				printf("\n:-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-] :-]  \n\n");
				printf("Shop location area:");
				gets_s(sahebshogl[tedsahebshogl].Shoplocationarea);

				tedsahebshogl++;

			}
			getchar();
			system("cls");
			printf("                      (-: Your account was created successfully :-)\n\n\n\n\n");
			getchar();
			system("cls");
			continue;
		}
		if ((!strcmp(d, "3")) || (!strcmp(d, "forget password")))
		{
			int peidakarbar = 0;
			system("cls");
			system("color 30");
			printf("email:");
			gets_s(emailfaramooshi);
			printf("\n\nusername:");
			gets_s(usernamefaramooshi);
			printf("\n\nnationalcode:");
			gets_s(nationalcodefaramooshi);
			for (int lo = 0; lo < tedkarbar; lo++)
			{
				if ((strcmp(karbareadii[lo].email, emailfaramooshi) == 0) && (strcmp(karbareadii[lo].username, usernamefaramooshi) == 0) && (strcmp(karbareadii[lo].nationalcode, nationalcodefaramooshi) == 0))
				{
					printf("\n\nThe desired user was found..\n\n");
					while (1) {
						printf("password:");

						int count = 0;
						while (1) {
							password1[count] = getch();
							if (password1[count] == '\b' && count > 0) {
								printf("\b \b");
								count--;
							}
							else if (password1[count] != '\r') {
								printf("*");
								count++;
							}
							else if (password1[count] == '\r') {
								count++;
								break;
							}
						}
						password1[count - 1] = '\0';
						printf("\n");
						printf("password(repetition):");

						count = 0;
						while (1) {
							password2[count] = getch();
							if (password2[count] == '\b' && count > 0) {
								printf("\b \b");
								count--;
							}
							else if (password2[count] != '\r') {
								printf("*");
								count++;
							}
							else if (password2[count] == '\r') {
								count++;
								break;
							}
						}
						password2[count - 1] = '\0';
						printf("\n");

						if (strcmp(password1, password2) == 0)
						{
							system("cls");
							strcpy(karbareadii[lo].password1, password1);

							printf("\npassword changed successfully\n\n");
							peidakarbar = 1;
							break;
						}
						if (strcmp(password1, password2) != 0)
						{
							system("cls");
							printf("\nEROR,The password and its repetition are not the same\n\n");
						}
					}

					continue;
				}
			}
			if (peidakarbar == 0) {
				for (int lo = 0; lo < tedsahebshogl; lo++)
				{
					if ((strcmp(sahebshogl[lo].emailshopowner, emailfaramooshi) == 0) && (strcmp(sahebshogl[lo].usernameshopowner, usernamefaramooshi) == 0) && (strcmp(sahebshogl[lo].nationalcodeshopowner, nationalcodefaramooshi) == 0))
					{
						printf("\n\nThe desired user was found..\n\n");
						while (1) {
							printf("password:");
							int count = 0;
							while (1) {
								passwordshopowner[count] = getch();
								if (passwordshopowner[count] == '\b' && count > 0) {
									printf("\b \b");
									count--;
								}
								else if (passwordshopowner[count] != '\r') {
									printf("*");
									count++;
								}
								else if (passwordshopowner[count] == '\r') {
									count++;
									break;
								}
							}
							passwordshopowner[count - 1] = '\0';
							printf("\n");
							printf("password(repetition):");
							count = 0;
							while (1) {
								passwordbikhodi[count] = getch();
								if (passwordbikhodi[count] == '\b' && count > 0) {
									printf("\b \b");
									count--;
								}
								else if (passwordbikhodi[count] != '\r') {
									printf("*");
									count++;
								}
								else if (passwordbikhodi[count] == '\r') {
									count++;
									break;
								}
							}
							passwordbikhodi[count - 1] = '\0';
							printf("\n");
							if (strcmp(passwordshopowner, passwordbikhodi) == 0)
							{
								system("cls");
								strcpy(sahebshogl[lo].passwordshopowner, passwordshopowner);
								printf("\npassword changed successfully\n\n");
								peidakarbar = 1;
								break;
							}
							if (strcmp(passwordshopowner, passwordbikhodi) != 0)
							{
								system("cls");
								printf("\nEROR,The password and its repetition are not the same\n\n");
							}
						}
						continue;
					}
				}
			}

			if ((peidakarbar == 0) && (strcmp(admin.emailadmin, emailfaramooshi) == 0) && (strcmp(admin.usernameadmin, usernamefaramooshi) == 0) && (strcmp(admin.natinalcodeadmin, nationalcodefaramooshi) == 0))
			{
				printf("\n\nThe desired user was found..\n\n");
				while (1) {
					printf("password:");
					int count = 0;
					while (1) {
						passwordadmin[count] = getch();
						if (passwordadmin[count] == '\b' && count > 0) {
							printf("\b \b");
							count--;
						}
						else if (passwordadmin[count] != '\r') {
							printf("*");
							count++;
						}
						else if (passwordadmin[count] == '\r') {
							count++;
							break;
						}
					}
					passwordadmin[count - 1] = '\0';
					printf("\n");
					printf("password(repetition):");
					count = 0;
					while (1) {
						passwordbikhodi[count] = getch();
						if (passwordbikhodi[count] == '\b' && count > 0) {
							printf("\b \b");
							count--;
						}
						else if (passwordbikhodi[count] != '\r') {
							printf("*");
							count++;
						}
						else if (passwordbikhodi[count] == '\r') {
							count++;
							break;
						}
					}
					passwordbikhodi[count - 1] = '\0';
					printf("\n");
					if (strcmp(passwordadmin, passwordbikhodi) == 0)
					{
						system("cls");
						strcpy(admin.passwordadmin, passwordshopowner);
						printf("\npassword changed successfully\n\n");
						peidakarbar = 1;
						break;
					}
					if (strcmp(passwordadmin, passwordbikhodi) != 0)
					{
						system("cls");
						printf("\nEROR,The password and its repetition are not the same\n\n");
					}
				}
				continue;
			}
			if (peidakarbar == 0)
			{
				system("cls");
				printf("Eror,there is no user with this profile\n\n");
				continue;
			}
		}

	}
}




