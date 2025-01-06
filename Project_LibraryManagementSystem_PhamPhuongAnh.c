#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 
struct Date{
	int day, month, year;
};

struct Book{
	char bookId[20];
	char title[50];
	char author[20];
	int quantity;
	int price;
	struct Date publish;
	
};

struct Client{
	char clientId[20];
	char name[20];
	char phoneNumber[20];
	bool status;
	struct Book BorrowedBooks;
};


struct Book book[100];
struct Client client[50];

//Ham show cac chuc nang quan li sach
void showBookMenu();

//1. Ham hien thi danh sach sach
void printList();

//2. Ham them sach
void addBook();

//3. Ham sua thong tin sach
void editBook();

//4. Ham xoa sach
void deleteBook();

//5. Ham tim sach theo ten 
void searchBook();

//6. Ham sap xep sach theo gia tien
void sortBook();

//Ham show cac chuc nang quan li khac hang
void showClientMenu();
 
//1. Ham hien thi danh sach sach
void printClientList();

//2. Ham them sach
void addClient();

//3. Ham sua thong tin sach
void updateClient();

//Ham khoa/ mo khoa khach hang
void unlockClient();

//Ham tim khach hang theo ten 
void searchClient();

//Ham xoa thong tin khach hang
void deleteClient();

//Ham cho muon sach
void borrowBook(); 

//Ham tra sach da muon
void returnBook(); 



//So luong sach da co trong file
int numberBook = 0;
//So luong khach hang da co trong file
int numberClient = 0; 

int choice, choice2, choice3;

int main(){
	do{
		printf("\n\n\n\t***HE THONG QUAN LY THU VIEN***\n");
		printf("\t===============================\n");
		printf("\t[1]. QUAN LY SACH\n");
		printf("\t[2]. QUAN LY KHACH HANG\n");
		printf("\t[0]. THOAT CHUONG TRINH \n");
		printf("\t===============================\n");
		printf("\tMOI NHAP LUA CHON: ");
		scanf("%d", &choice2);
		switch(choice2){
			case 1:
				printf("\n\tBAN DA CHON QUAN LY SACH !!\n");
				showBookMenu();
				break;
			case 2:
				printf("\n\tBAN DA CHON QUAN LY KHACH HANG !!\n");
				showClientMenu();
				break;
			case 0:
				printf("\n\tTHOAT CHUONG TRINH !!!");
				printf("\n\t=========== CAM ON !! ===========");
				printf("\n\t======== HEN GAP LAI !! =========");
				exit(0);
				
				break;
			default:
				printf("\n\t\tKHONG CO CHUC NANG NAY!!");
	}
	}while(1);

	return 0;
}

void printList(){
	
	FILE *file = fopen("booklist.bin", "rb");
	numberBook = fread(&book, sizeof(struct Book), 100, file); 
	
	printf("\t%d\n", numberBook);
	
	if(numberBook == 0){
		printf("\tDANH SACH RONG !!\n");
		
	}else{
		printf("\tDANH SACH SACH: \n");
		
		printf("\n\t\t\t******* BOOKLIST ********\n");
		printf("========|================================|======================|================|==========|====================\n");
		printf("   ID   |        TEN SACH                |  TEN TAC GIA         |    GIA TIEN    | SO LUONG |   NGAY XUAT BAN    \n");
				
		for(int i=0; i<numberBook; i++){
			printf("--------|--------------------------------|----------------------|----------------|----------|--------------------\n");
			printf(" %-6s | %-30s | %-20s | %-10d VND | %-9d| %d/%d/%d\n", book[i].bookId,book[i].title, book[i].author, book[i].price, book[i].quantity, book[i].publish.day, book[i].publish.month, book[i].publish.year ); 
		}
		fclose(file);
	}
	printf("=================================================================================================================\n");

	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\n\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
	
}

void  addBook(){
	
	struct Book book1;
	int choice1, temp, index, flag1=0;
	 
	
	FILE *fptr = fopen("booklist.bin", "rb");
	numberBook = fread(&book, sizeof(struct Book), 100, fptr);
	
	if(numberBook>=100){
		printf("\n\tDANH SACH SACH DA DAY !!");
		return;
	}else{	
		printf("\n\tBAN DA CHON THEM SACH !!\n");

		
		printf("\t%d\n", numberBook);
		printf("\tMOI NHAP ID SACH : ");
		
	 	
		do {
			temp=0;
			fgets(book1.bookId, 20, stdin);
			book1.bookId[strcspn(book1.bookId,"\n")]='\0';
			
			int len = strlen(book1.bookId);

			for(int i=0; i<numberBook; i++){
				if(strcmp(book1.bookId, book[i].bookId)==0){
					temp=1;
					
				}
			}
			if( temp==1){
				printf("\t\tID SACH DA TON TAI: ");
			}
			
			if(strlen(book1.bookId)==0){
				printf("\t\tID SACH KHONG DE TRONG, MOI NHAP LAI: ");
				temp=1;
			}
			
		}while(temp == 1);


	 
	
	fflush(stdin);
	printf("\tNHAP TEN SACH: ");
	 
	do{
		flag1 = 0; 
		fgets(book1.title, sizeof(book1.title), stdin);
		book1.title[strcspn(book1.title, "\n")] = '\0';
		
		int len = strlen(book1.title);

	    for(int i=0; i<numberBook; i++){
	    	if(strcmp(book1.title, book[i].title)==0){
	    	flag1 = 1;
		    }
		}
	    
	    if (flag1==1) {
	        printf("\t\tTEN SACH DA TON TAI, MOI NHAP LAI: ");
	        flag1 = 1;
	    }
	    
	    if(len==0){
	    	printf("\t\tTEN SACH KHONG DUOC BO TRONG, MOI NHAP LAI: ");
	    	flag1=1;
		}
	    
	
	}while(flag1==1);
		
	fflush(stdin);
	fclose(fptr);
	
	printf("\tMOI NHAP TAC GIA : ");
	do{
		flag1 = 0;
		fgets(book1.author, sizeof(book1.author), stdin);
		book1.author[strcspn(book1.author, "\n")] = '\0';
		
		int len = strlen(book1.author);

	    if (len == 0 ) {
	        printf("\t\tTEN TAC GIA KHONG DE TRONG, MOI NHAP LAI: ");
			flag1 = 1;
	    }
	    

	}while(flag1==1);
			
	} 
	
	fflush(stdin);	
	printf("\tNGAY XUAT BAN: ");
	
	do{
		flag1=0;
		scanf("%d", &book1.publish.day);
		if(book1.publish.day>31 || book1.publish.day < 1){
			printf("\t\tNGAY KHONG HOP LE, MOI NHAP LAI:  ");
			flag1 = 0;
			
		}else{
			flag1 = 1;
		}
		
		
	}while(flag1==0);
	fflush(stdin);
	
	printf("\tTHANG XUAT BAN: ");
	do{
		flag1=0;
		scanf("%d", &book1.publish.month);
		if(book1.publish.month>12 || book1.publish.month < 1){
			printf("\t\tTHANG KHONG HOP LE, MOI NHAP LAI:  ");
			flag1 = 0;
			
		}else{
			flag1 = 1;
		}
		
		
	}while(flag1==0);
	fflush(stdin);
	
	
	printf("\tNAM XUAT BAN: ");
	do{
		flag1=0;
		scanf("%d", &book1.publish.year);
		if(book1.publish.year>2024 || book1.publish.year < 1000){
			printf("\t\tNAM KHONG HOP LE, MOI NHAP LAI:  ");
			flag1 = 0;
			
		}else{
			flag1 = 1;
		}
	
	}while(flag1==0);
	fflush(stdin);
	
	
	
	printf("\tNHAP GIA TIEN: ");
	scanf("%d", &book1.price);
	
	printf("\tNHAP SO LUONG NHAP: ");
	scanf("%d", &book1.quantity);

	 
	
	numberBook++;
	
		
	
	
	FILE *file=fopen("booklist.bin", "ab");
	fwrite(&book1, sizeof(book1), 1, file);
	
	
	fclose(file);
	
	

	printf("\n\tTHEM SACH THANH CONG !!");
	

	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}

}

//Ham sua du lieu sach
void editBook(){
	printf("\tSUA THONG TIN SACH !!\n");
	int temp, index;
	char check[20];
	printf("\tNHAP ID SACH CAN SUA: ");
	fgets(check, 20, stdin);
	check[strlen(check)-1]='\0';
	
	FILE *fptr = fopen("booklist.bin", "rb");
	numberBook = fread(&book, sizeof(struct Book), 100, fptr); 
	
	temp=0;
	for(int i=0; i<numberBook; i++){
		if(strcmp(check, book[i].bookId)== 0){
			index = i;
			temp = 1;
			break;
		}
	}
	fclose(fptr);
	if(temp==0){
		printf("\n\tKHONG TIM THAY SACH CAN SUA !!");
	}else{
		
		printf("\n\tSACH CAN SUA: \n");
		printf("\n\t****************************************BOOKLIST********************************************\n");
		printf("========|================================|======================|================|==========|===================\n");
		printf("   ID   |        TEN SACH                |  TEN TAC GIA         |    GIA TIEN    | SO LUONG |   NGAY XUAT BAN   \n");
				
		
		printf("--------|--------------------------------|----------------------|----------------|----------|--------------------\n");
		printf(" %-6s | %-30s | %-20s | %-14d | %-9d| %d/%d/%d\n", book[index].bookId,book[index].title, book[index].author, book[index].price, book[index].quantity, book[index].publish.day, book[index].publish.month, book[index].publish.year ); 

		
		printf("\n\tNHAP THONG TIN CAN SUA \n"); 
		fflush(stdin);
		
		printf("\tNHAP TEN SACH: "); 
		
		
		do{
			temp=0;
			fgets(book[index].title, 50, stdin);
			book[index].title[strcspn(book[index].title,"\n")]='\0';
			
			int len = strlen(book[index].title);
			if(len==0){
				printf("\t\tTEN SACH KHONG DE TRONG, MOI NHAP LAI:  ");
				temp=1;
			}

		}while(temp==1);
		
		
		printf("\tNHAP TAC GIA: ");

		do{
			temp=0;
			fgets(book[index].author, 20, stdin);
			book[index].author[strcspn(book[index].author,"\n")]='\0';
			
			int len = strlen(book[index].author);
			if(len==0){
				printf("\t\tTEN TAC GIA KHONG DE TRONG, MOI NHAP LAI:  ");
				temp=1;
			}
			
			
		}while(temp==1);
		
		fflush(stdin);	
		printf("\tNGAY XUAT BAN: ");
		
		do{
			temp=0;
			scanf("%d", &book[index].publish.day);
			if(book[index].publish.day>31 || book[index].publish.day < 1){
				printf("\t\tNGAY KHONG HOP LE, MOI NHAP LAI:  ");
				temp = 0;
				
			}else{
				temp = 1;
			}
			
			
		}while(temp==0);
		fflush(stdin);
		
		printf("\tTHANG XUAT BAN: ");
		do{
			temp=0;
			scanf("%d", &book[index].publish.month);
			if(book[index].publish.month>12 || book[index].publish.month < 1){
				printf("\t\tTHANG KHONG HOP LE, MOI NHAP LAI:  ");
				temp = 0;
				
			}else{
				temp = 1;
			}
			
			
		}while(temp==0);
		fflush(stdin);
		
		
		printf("\tNAM XUAT BAN: ");
		do{
			temp=0;
			scanf("%d", &book[index].publish.year);
			if(book[index].publish.year>2025 || book[index].publish.year < 1000){
				printf("\t\tNAM KHONG HOP LE, MOI NHAP LAI:  ");
				temp = 0;
				
			}else{
				temp = 1;
			}
		
		}while(temp==0);
		fflush(stdin);
		
		printf("\tGIA TIEN: ");
		scanf("%d", &book[index].price);
		
		printf("\tSO LUONG NHAP: ");
		scanf("%d", &book[index].quantity);
		fflush(stdin);
		
		FILE *file=fopen("booklist.bin","wb");
		if(file==NULL){
			printf("LOI MO FILE!");
		}
		
		fwrite(&book, sizeof(struct Book), numberBook, file);
		fclose(file);
		printf("\n\tSUA THONG TIN SACH THANH CONG !!");
	}
	
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
}
//Ham xoa thong tin sach 
void deleteBook(){
	int temp=0, index;
	
	char erase[20];
	
	printf("\tMOI NHAP ID SACH CAN XOA: ");
	fgets(erase, 20, stdin);
	erase[strcspn(erase, "\n")] = '\0';
	
	FILE *fptr = fopen("booklist.bin", "rb");
	numberBook = fread(&book, sizeof(struct Book), 100, fptr);
	
	for(int i=0;i<numberBook; i++){
		if(strcmp(erase, book[i].bookId) == 0){
			index = i;
			temp = 1;
			break;	
		}
	}
	fclose(fptr);
	
	if(temp == 0){
		printf("\n\tID SACH KHONG TON TAI !!");
	}else{
		int deleteChoice;
		printf("\n\tXAC NHAN XOA [1]  HUY [0]    :");
		scanf("%d", &deleteChoice);
		if(deleteChoice==1){
			for(int i=index; i<numberBook; i++){
			book[i] = book[i+1];
		}
		numberBook--;
		FILE *file=fopen("booklist.bin","wb");
		if(file==NULL){
			printf("\n\tLOI MO FILE!");
		}
		fwrite(&book, sizeof(struct Book), numberBook, file);
		fclose(file);
		printf("\n\tXOA SACH THANH CONG !!");
		}else if(deleteChoice == 0){
			printf("\n\tHUY XOA SACH !!\n");
		}

	}
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}

}

//Ham tim sach 
void searchBook(){
	int index, temp = 0; 
	char check [20];
	printf("\tMOI NHAP SACH CAN TIM: ");
	fgets(check, 20, stdin);
	check[strcspn(check, "\n")] = '\0';
	char *str; 
	FILE *file = fopen("booklist.bin", "rb");
	numberBook = fread(&book, sizeof(struct Book), 100, file);
	
	printf("\n\tSACH CAN TIM: \n");
	printf("\n\t****************************************BOOKLIST********************************************\n");
	printf("========|================================|======================|================|==========|====================\n");
	printf("   ID   |        TEN SACH                |  TEN TAC GIA         |    GIA TIEN    | SO LUONG |   NGAY XUAT BAN   \n");

	for(int i=0; i<numberBook; i++){
		str = strstr(book[i].title, check); 
		if(str){
			index = i;
			temp++; 
			printf("--------|--------------------------------|----------------------|----------------|----------|--------------------\n");
			printf(" %-6s | %-30s | %-20s | %-10d VND | %-9d| %d/%d/%d\n", book[index].bookId,book[index].title, book[index].author, book[index].price, book[index].quantity, book[index].publish.day, book[index].publish.month, book[index].publish.year ); 
 
		}
	}
	fclose(file);
	
	if(temp==0){
		printf("===================================================================================================================\n");
		printf("\n\tKHONG THAY SACH CAN TIM !!!");
	}
	
	
		
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
	
}


void sortBook(){
	char sortChoice;
	printf("\n\ta. SAP XEP TANG DAN \n");
	printf("\tb. SAP XEP GIAM DAN        :");
	scanf("%c",&sortChoice);
	
	if(sortChoice=='a' || sortChoice=='A'   ){
		printf("\n\tDANH SACH TANG DAN: \n");
	
	
	printf("\tDANH SACH SAU KHI SAP XEP: \n");
	struct Book temp;
	for(int i=0; i<numberBook; i++){
		for(int j=0; j<numberBook-1-i; j++){
			if(book[j].price>book[j+1].price){
				temp = book[j];
				book[j] = book[j+1];
				book[j+1] = temp;
			} 
		} 
	}
	FILE *file = fopen("booklist.bin", "wb");
	for(int i=0; i<numberBook; i++){
		fwrite(&book[i], sizeof(struct Book), 1, file);
	}
	fclose(file);
	FILE *file1 = fopen("booklist.bin","rb");
	numberBook = fread(&book, sizeof(struct Book), 100, file1);
	printf("\n\t\t\t********BOOKLIST********\n");
	printf("========|================================|======================|================|==========|===================\n");
	printf("   ID   |        TEN SACH                |  TEN TAC GIA         |    GIA TIEN    | SO LUONG |   NGAY XUAT BAN   \n");
			
	for(int i=0; i<numberBook; i++){
		printf("--------|--------------------------------|----------------------|----------------|----------|-------------------\n");
		printf(" %-6s | %-30s | %-20s | %-10d VND | %-9d| %d/%d/%d\n", book[i].bookId,book[i].title, book[i].author, book[i].price, book[i].quantity, book[i].publish.day, book[i].publish.month, book[i].publish.year ); 
	}
	fclose(file1);
	printf("=================================================================================================================\n");
	printf("\n\tSAP XEP TANG DAN THANH CONG !!");
	
	}
	else if(sortChoice=='b' || sortChoice=='B'){
		printf("\n\tDANH SACH GIAM DAN: \n");
	
		FILE *fptr = fopen("booklist.bin", "wb");
		printf("\tDANH SACH SAU KHI SAP XEP: \n");
		struct Book temp;
		for(int i=0; i<numberBook; i++){
			for(int j=0; j<numberBook-1-i; j++){
				if(book[j].price<book[j+1].price){
					temp = book[j];
					book[j] = book[j+1];
					book[j+1] = temp;
				} 
			} 
		}
		
		for(int i=0; i<numberBook; i++){
			fwrite(&book[i], sizeof(struct Book), 1, fptr);
		}
		fclose(fptr);
		FILE *fptr1 = fopen("booklist.bin","rb");
		numberBook = fread(&book, sizeof(struct Book), 100, fptr1);
		printf("\n\t\t\t********BOOKLIST********\n");
		printf("========|================================|======================|================|==========|====================\n");
		printf("   ID   |        TEN SACH                |  TEN TAC GIA         |    GIA TIEN    | SO LUONG |   NGAY XUAT BAN   \n");
				
		for(int i=0; i<numberBook; i++){
			printf("--------|--------------------------------|----------------------|----------------|----------|--------------------\n");
			printf(" %-6s | %-30s | %-20s | %-10d VND | %-9d| %d/%d/%d\n", book[i].bookId,book[i].title, book[i].author, book[i].price, book[i].quantity, book[i].publish.day, book[i].publish.month, book[i].publish.year ); 
		}
		fclose(fptr1);
		printf("=================================================================================================================\n");
		printf("\n\tSAP XEP GIAM DAN THANH CONG !!"); 
	}

	
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
}



void showBookMenu(){
	do{
		printf("\n\n\n\n\n\t***HE THONG QUAN LY THU VIEN***\n");
		printf("\n\t\t- QUAN LI SACH -\t\n");
		printf("\t===============================\n");
		printf("\t[1]. HIEN THI DANH SACH SACH\n");
		printf("\t[2]. THEM SACH\n");
		printf("\t[3]. SUA THONG TIN SACH \n");
		printf("\t[4]. XOA SACH\n");
		printf("\t[5]. TIM KIEM SACH\n");
		printf("\t[6]. SAP XEP SACH\n");
		printf("\t[7]. QUAY LAI MENU CHINH  !!\n");
		printf("\t[0]. THOAT CHUONG TRINH!!\n");
		printf("\t===============================\n");
		printf("\tMOI NHAP LUA CHON: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice){
			case 1:
				printList();
				break;
			case 2:
				addBook();
				break;
			case 3:
				editBook();
				break;
			case 4:
				deleteBook();
				break;
			case 5:
				searchBook();
				break;
			case 6:
				sortBook();
				break;
			case 7:
				return;
			case 0:
				printf("\tBAN DA THOAT !!!");
				printf("\n\t=========== CAM ON !! ===========");
				printf("\n\t======== HEN GAP LAI !! =========");
				exit(0);
				break;
		}
		}while(1);
}

//Ham in ra menu quan li khach hang
void showClientMenu(){
	do{
		printf("\n\n\n\n\n\t***HE THONG QUAN LY THU VIEN***\n");
		printf("\n\t  - QUAN LI KHACH HANG -\t\n");
		printf("\t==================================\n");
		printf("\t[1]. HIEN THI DANH SACH KHACH HANG\n");
		printf("\t[2]. THEM KHACH HANG\n");
		printf("\t[3]. SUA THONG TIN KHACH HANG \n");
		printf("\t[4]. KHOA (MO KHOA) KHACH HANG\n");
		printf("\t[5]. TIM KIEM KHACH HANG\n");
		printf("\t[6]. XOA THONG TIN KHACH HANG\n");
		printf("\t[7]. MUON SACH\n");
		printf("\t[8]. TRA SACH DA MUON\n");
		printf("\t[9]. QUAY LAI MENU CHINH!!\n");
		printf("\t[0]. THOAT CHUONG TRINH !!\n");
		printf("\t==================================\n");
		printf("\tMOI NHAP LUA CHON: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice){
			case 1:
				printClientList();
				break;
			case 2:
				addClient();
				break;
			case 3:
				updateClient();
				break;
			case 4:
				unlockClient();
				break;
			case 5:
				searchClient();
				break;
			case 6:
				deleteClient();
				break;
			case 7:
				borrowBook();
				break;
			case 8:
				returnBook();
				break;
			case 9:
				return;
			case 0:
				printf("\tBAN DA THOAT !!!");
				printf("\n\t=========== CAM ON !! ===========");
				printf("\n\t======== HEN GAP LAI !! =========");
				exit(0);
				break;
			}
		}while(1);
	}
	
//Ham in ra danh sach khach hang
void printClientList(){
	FILE *file = fopen("clientlist.bin", "rb");
	numberClient = fread(&client, sizeof(struct Client), 50, file);
	
	if(numberClient==0){
		printf("\n\tDANH SACH KHACH HANG RONG!!\n");
		printf("\n\t=================================\n");
	}else{
		
		printf("\n\t\tDANH SACH KHACH HANG\n");
		printf("========|==========================|================|================|=================================|==========|\n");
		printf("   ID   |        TEN KHACH HANG    |  SO DIEN THOAI |   TRANG THAI   |          SACH DA MUON           | SO LUONG |\n");
		for(int i=0; i<numberClient; i++){
			printf("--------|--------------------------|----------------|----------------|---------------------------------|----------|\n");
			printf(" %-6s | %-24s | %14s | %-14s | %-31s | %-8d |\n", client[i].clientId,client[i].name, client[i].phoneNumber, client[i].status? "KHOA" : "MO", client[i].BorrowedBooks.title, client[i].BorrowedBooks.quantity );
		}
		printf("===================================================================================================================\n");

	}
	fclose(file); 

	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
}

//Ham sua thong tin khach hang
void addClient(){
	
	printf("\tNHAP DU LIEU KHACH HANG !!\n");
	struct Client client1;
	int temp = 0; 
	printf("\tNHAP ID KHACH HANG: ");
	
	FILE *file = fopen("clientlist.bin", "rb");
	numberClient = fread(&client, sizeof(struct Client), 50, file);
	
	do{
		temp=0; 
		fgets(client1.clientId, 20, stdin);
		client1.clientId[strcspn(client1.clientId,"\n")]='\0';
		for(int i=0; i<numberClient; i++){
			if(strcmp(client1.clientId,client[i].clientId)==0){
				temp = 1;
				break; 
			}
		}
		if(temp==1){
			printf("\t\tID KHACH HANG DA TON TAI, MOI NHAP LAI: ");
		}	 
	}while(temp==1);
	fclose(file);
	
	char clientNameCheck[20]; 
	printf("\tNHAP TEN KHACH HANG: "); 
	
	do{
		temp = 0;
		fgets(clientNameCheck, 50, stdin);
		clientNameCheck[strcspn(clientNameCheck,"\n")]='\0';
		int len = strlen(clientNameCheck);
		if(len==0 || len>25){
			printf("\t\tTEN KHONG HOP LE, MOI NHAP LAI: ");
			temp=1;
		}
	}while(temp==1);
	strcpy(client1.name, clientNameCheck);
	fflush(stdin); 
	
	char phoneNumCheck[20]; 
	printf("\tNHAP SO DIEN THOAI: ");
	do{
		temp = 0;
		fgets(phoneNumCheck, 20, stdin);
		phoneNumCheck[strcspn(phoneNumCheck, "\n")] = '\0';
		
		for(int i=0; i<numberClient; i++){
			if( strcmp(phoneNumCheck, client[i].phoneNumber) == 0 || strlen(phoneNumCheck)!=10 ){
				temp=1;
				
			}	
		}if(temp==1){
			printf("\t\tSO DIEN THOAI KHONG HOP LE, MOI NHAP LAI: ");
		}
	}while(temp==1);
	
	strcpy(client1.phoneNumber, phoneNumCheck); 
	
	fflush(stdin);
	
	
	int getStatus;
	printf("\tNHAP TRANG THAI KHACH HANG - [1].KHOA   [0].MO KHOA :  ");
	
	do{
		scanf("%d", &getStatus);
		if(getStatus==1){
			client1.status=true;
			printf("\t\tKHACH HANG DA DUOC KHOA !\n"); 
			break;
		}else if(getStatus==0){
			client1.status=false;
			printf("\t\tKHACH HANG DUOC MO KHOA !\n");
			break;
		}else{
			printf("\n\tDU LIEU NHAP KHONG HOP LE, MOI NHAP LAI: ");
		}
	}while(1);
	fflush(stdin);
		
	FILE *fptr = fopen("clientlist.bin", "ab");
	fwrite(&client1, sizeof(struct Client), 1, fptr);
	fclose(fptr);
	 
	FILE *fptr1 = fopen(" booklist.bin", "wb");
	fwrite(&book, sizeof(struct Book), numberBook, fptr1);
	fclose(fptr1);
	
	numberClient++; 
	printf("\n\tTHEM KHACH HANG THANH CONG !!!");
	
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
	
}
	

void  updateClient(){
	printf("\n\tNHAP ID KHACH HANG CAN SUA: ");
	int temp, index, flag;
	char check[20];
	
	fgets(check, 20, stdin);
	check[strlen(check)-1]='\0';
	
	FILE *fptr = fopen("clientlist.bin", "rb");
	numberClient = fread(&client, sizeof(struct Client), 50, fptr); 
	temp=0;
	for(int i=0; i<numberClient; i++){
		if(strcmp(check, client[i].clientId)== 0){
			index = i;
			temp = 1;
			break;
		}
	}
	fclose(fptr);
	if(temp==0){
		printf("\n\tKHONG TIM THAY THONG TIN KHACH HANG !!");
	}else{
		
		printf("\n\tKHACH HANG CAN SUA: \n");
		printf("\n\t\t\t\t\t********CLIENTLIST********\n");
		printf("========|===========================|======================|================|==========================|==========\n");
		printf("   ID   |       TEN KHACH HANG      |    SO DIEN THOAI     |   TRANG THAI   |       SACH DA MUON       | SO LUONG \n");	
		printf("--------|---------------------------|----------------------|----------------|--------------------------|----------\n");
		printf("%-8s| %-25s | %20s | %-14s | %-24s | %-8d", client[index].clientId, client[index].name, client[index].phoneNumber, client[index].status?"KHOA":"MO", client[index].BorrowedBooks.title, client[index].BorrowedBooks.quantity ); 

		
		printf("\n\n\tNHAP THONG TIN CAN SUA \n"); 
		fflush(stdin);
		char clientNameCheck[20]; 
		printf("\tNHAP TEN KHACH HANG: "); 
		
		do{
			temp = 0;
			fgets(clientNameCheck, 50, stdin);
			clientNameCheck[strcspn(clientNameCheck,"\n")]='\0';
			int len = strlen(clientNameCheck);
			if(len==0 || len>25){
				printf("\t\tTEN KHONG HOP LE, MOI NHAP LAI: ");
				temp=1;
			}
		}while(temp==1);
		strcpy(client[index].name, clientNameCheck);
		
		
		char phoneNumCheck[20]; 
		printf("\tNHAP SO DIEN THOAI: ");
		do{
			temp = 0;
			fgets(phoneNumCheck, 20, stdin);
			phoneNumCheck[strcspn(phoneNumCheck, "\n")] = '\0';
			
			for(int i=0; i<numberClient; i++){
				if( strcmp(phoneNumCheck, client[i].phoneNumber) == 0 || strlen(phoneNumCheck)!=10 ){
					temp=1;
					
				}	
			}if(temp==1){
				printf("\t\tSO DIEN THOAI KHONG HOP LE, MOI NHAP LAI: ");
			}
		}while(temp==1);
		
		strcpy(client[index].phoneNumber, phoneNumCheck); 
		
		fflush(stdin);
			
		
		FILE *fileClient=fopen("clientlist.bin","wb");
		if(fileClient==NULL){
			printf("LOI MO FILE!");
		}
		
		fwrite(&client, sizeof(struct Client), numberClient, fileClient);
		fclose(fileClient);
		printf("\n\tSUA THONG TIN THANH CONG !!");
	}
	
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}

}

//Mo khoa hoac khoa khach hang

void unlockClient(){
		char id_unlock[20];
		
		printf("\n\tNHAP ID KHACH HANG CAN CAP NHAT TRANG THAI:  ");
		fgets(id_unlock, 20, stdin);
		id_unlock[strcspn(id_unlock, "\n")]='\0';
		
		FILE *fileLock = fopen("clientlist.bin", "rb");
		numberClient = fread(&client, sizeof(struct Client), 50, fileLock);
		
		int temp=0, index;
		for(int i=0; i<numberClient; i++){
			if(strcmp(id_unlock, client[i].clientId)==0){
				temp=1;
				index = i;
				break;
			}
		}
		
		fclose(fileLock);
		
		
		
		FILE *file = fopen("clientlist.bin", "rb");
		numberClient = fread(&client, sizeof(struct Client), 50, file);
		
		if(temp==0){
			printf("\nID KHACH HANG KHONG TON TAI !!");			
		}else{
			printf("\n\tKHACH HANG CAN CAP NHAT: \n");
			printf("\t ID: %s\n\t TEN KHACH HANG: %s\n\t TRANG THAI: %s \n", client[index].clientId, client[index].name, client[index].status?"DANG KHOA":"DANG MO"); 

			fclose(file);
			
			printf("\n\n\t[1].KHOA   [0].MO KHOA ");
			int updateStatus; 
			
			do{
				scanf("%d", &updateStatus);
				if(updateStatus==1){
					client[index].status=true;
					printf("\tKHACH HANG DA DUOC KHOA THANH CONG !\n"); 
					break;
				}else if(updateStatus==0){
					client[index].status=false;
					printf("\t\tKHACH HANG DUOC MO KHOA THANH CONG !\n");
					break;
				}else{
					printf("\n\tDU LIEU NHAP KHONG HOP LE, MOI NHAP LAI: \n");
				}
			}while(1);
			}
		FILE *fptr = fopen("clientlist.bin", "wb");
		fwrite(&client, sizeof(struct Client), numberClient, fptr);
		
		fclose(fptr);	
		fflush(stdin);
		
		printf("\n\t==================================\n");
		printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
		scanf("%d", &choice3);
		while(1){
			if(choice3==1){
				return;
			}else{
				printf("\tTHOAT CHUONG TRINH !!!");
				printf("\n\t=========== CAM ON !! ===========");
				printf("\n\t======== HEN GAP LAI !! =========");
				exit(0);
				break;
			}
		}
		
}
void searchClient(){
	int index, temp=0;
	char clientName[20];
	printf("\tNHAP TEN KHACH HANG CAN TIM:  ");
	fgets(clientName, 20, stdin);
	clientName[strcspn(clientName, "\n")] = '\0';
	
	FILE *file = fopen("clientlist.bin", "rb");
	numberClient = fread(&client, sizeof(struct Client), 50, file);
	
	char *str;
	printf("\n\tKHACH HANG CAN TIM !!\n");
	printf("\n\t\t\t\t\t********CLIENTLIST********\n");
	printf("=========|===========================|======================|================|==========================|==========\n");
	printf("    ID   |       TEN KHACH HANG      |    SO DIEN THOAI     |   TRANG THAI   |       SACH DA MUON       | SO LUONG  ");
	
	for(int i=0; i<numberClient; i++){
		str = strstr( client[i].name, clientName);
		if(str){
			index = i;
			temp=1;
			printf("\n---------|---------------------------|----------------------|----------------|--------------------------|----------\n");
			printf(" %-8s| %-25s | %20s | %-14s |  %-23s | %-8d", client[index].clientId, client[index].name, client[index].phoneNumber, client[index].status?"KHOA":"MO", client[index].BorrowedBooks.title, client[index].BorrowedBooks.quantity ); 
		}
	}

	if(temp==0){
		printf("\n==================================================================================================================");
		printf("\n\tKHONG THAY KHACH HANG CAN TIM !!\n");
	}
	
	fclose(file);
	fflush(stdin);
	
	
	printf("\n==================================================================================================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
} 


void deleteClient(){
	int temp=0, index;
	
	char erase[20];
	
	printf("\tMOI NHAP ID SACH CAN XOA: ");
	fgets(erase, 20, stdin);
	erase[strcspn(erase, "\n")] = '\0';
	
	FILE *fptr = fopen("clientlist.bin", "rb");
	numberClient = fread(&book, sizeof(struct Client), 100, fptr);
	
	for(int i=0;i<numberClient; i++){
		if(strcmp(erase, client[i].clientId) == 0){
			index = i;
			temp = 1;
			break;	
		}
	}
	fclose(fptr);
	
	if(temp == 0){
		printf("\n ID KHACH HANG KHONG TON TAI !!");
	}else{
		int deleteChoice;
		printf("\n\tXAC NHAN XOA [1]  HUY [0]    :");
		scanf("%d", &deleteChoice);
		if(deleteChoice==1){
			for(int i=index; i<numberClient; i++){
			client[i] = client[i+1];
		}
		numberClient--;
		FILE *file=fopen("clientlist.bin","wb");
		if(file==NULL){
			printf("\n\tLOI MO FILE!");
		}
		fwrite(&client, sizeof(struct Client), numberClient, file);
		fclose(file);
		printf("\n\tXOA KHACH HANG THANH CONG !!");
		}else if(deleteChoice == 0){
			printf("\n\tHUY XOA KHACH HANG !!\n");
		}

	}
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}

}

//Ham cho khach hang muon sach
void borrowBook(){
	int indexClient, indexBook, temp, flag;
	char idClientBorrow[20]; 
	printf("\n\tNHAP ID KHACH HANG CAN MUON SACH:  ");
	
	FILE *file = fopen("clientlist.bin", "rb");
	numberClient = fread(&client, sizeof(struct Client), 50, file);	 
	do{
		temp = 0;
		fgets(idClientBorrow, 20, stdin);
		idClientBorrow[strcspn(idClientBorrow, "\n")] = '\0';
		
		for(int i=0; i<numberClient; i++){
			if(strcmp(idClientBorrow, client[i].clientId) == 0){
				indexClient = i;
				temp = 1;
				fclose(file);
				break;
			}
		}
		if(temp==0){
			printf("\t\tID KHACH HANG KHONG TON TAI, MOI CHON LAI:  ");
		}
	}while(temp==0);
	
	if(client[indexClient].status == 0){
		printf("\n\tKHACH HANG DANG DUOC MO !!\n");
		
		printf("\tNHAP ID SACH CAN MUON: ");
		 
		FILE *fptr = fopen("booklist.bin", "rb");
		numberBook = fread(&book, sizeof(struct Book), 100, fptr); 
		do{
			
			flag = 0;
			fgets(client[indexClient].BorrowedBooks.bookId, 50, stdin);
			client[indexClient].BorrowedBooks.bookId[strcspn(client[indexClient].BorrowedBooks.bookId, "\n")] = '\0';
			
			
			
			for(int i=0; i<numberBook; i++){
				if(strcmp(client[indexClient].BorrowedBooks.bookId, book[i].bookId) == 0){
					flag = 1;
					indexBook = i;
					break;
				}
			}
			if(flag==0){
				printf("\t\tSACH KHONG TON TAI, MOI NHAP LAI:  ");
			}
		}while(flag!=1);
		
		strcpy(client[indexClient].BorrowedBooks.title, book[indexBook].title);
		printf("\tSACH : %s\n", client[indexClient].BorrowedBooks.title);
		
		printf("\tNHAP SO LUONG SACH CAN MUON (Toi da 5 cuon): ");
		
		do{
			flag = 0;
			scanf("%d", &client[indexClient].BorrowedBooks.quantity);
			fflush(stdin); 
			int  borrowedBooksQuantity = client[indexClient].BorrowedBooks.quantity;
			if(borrowedBooksQuantity <= book[indexBook].quantity && borrowedBooksQuantity <= 5){
				flag = 1;
				book[indexBook].quantity-=client[indexClient].BorrowedBooks.quantity; 
				break;
			}
			if(flag!=1){
				printf("\t\tKHONG DU SO LUONG SACH CAN MUON, MOI NHAP LAI ");
			}
		}while(flag!=1);
		printf("\n\tMUON SACH THANH CONG !!!\n");
		fclose(fptr);
		
		FILE *fileBook = fopen("booklist.bin", "wb");
		fwrite(&book, sizeof(struct Book), numberBook, fileBook);
		fclose(fileBook);
		
	}else if (client[indexClient].status == 1){
		printf("\n\tKHACH HANG DANG KHOA, VUI LONG MO KHOA DE MUON SACH !!\n");
	}
	
	FILE *fileClient = fopen("clientlist.bin", "wb");
	fwrite(&client, sizeof(struct Client), numberClient, fileClient);
	fclose(fileClient);
	
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
} 

//Ham tra sach
void returnBook(){
	
	int temp, indexClient; 
	char idClientReturn[20]; 
	printf("\n\tNHAP ID KHACH HANG MUON TRA:  ");
	FILE *file = fopen("clientlist.bin", "rb");
	numberClient = fread(&client, sizeof(struct Client), 50, file);
	
	do{
		temp=0; 
		fgets(idClientReturn, 20, stdin);
		idClientReturn[strcspn(idClientReturn, "\n")] = '\0';
		
		for(int i=0; i<numberClient; i++){
			if(strcmp(idClientReturn, client[i].clientId) == 0){
				indexClient = i;
				temp = 1;
				break; 
			}
		}
		if(temp==0){
			printf("\n\t\tKHACH HANG KHONG TON TAI,  NHAP LAI:  "); 
		}
	}while(temp==0);
	fclose(file); 
	
	int len = strlen(client[indexClient].BorrowedBooks.title);
	if(len==0){
		printf("\n\t\tKHONG CO SACH NAO DA MUON !!"); 
	}else{
		printf("\n\t\tSACH DA MUON: %s\n", client[indexClient].BorrowedBooks.title);
		printf("\t\tSO LUONG:  %d", client[indexClient].BorrowedBooks.quantity);
		
		FILE *fptr = fopen("booklist.bin", "rb");
		numberBook = fread(&book, sizeof(struct Book), 50, fptr);
		
		int indexBook;
		for(int i=0; i<numberBook; i++){
			if(strcmp(client[indexClient].BorrowedBooks.title, book[i].title)==0){
				indexBook = i;
				break;
			}
		}
		
		
		strcpy(client[indexClient].BorrowedBooks.title," ");
		book[indexBook].quantity += client[indexClient].BorrowedBooks.quantity; 
		client[indexClient].BorrowedBooks.quantity = 0;
		
		FILE *fptrBook = fopen("booklist.bin", "wb");
		fwrite(&book, sizeof(struct Book), numberBook, fptrBook);
		fclose(fptrBook);
	}
	
	FILE *fptr = fopen("clientlist.bin", "wb");
	fwrite(&client, sizeof(struct Client), numberClient, fptr);
	fclose(fptr); 
	
	printf("\n\t==================================\n");
	printf("\tQUAY VE MENU [1] or THOAT[0]:  ");
	scanf("%d", &choice3);
	while(1){
		if(choice3==1){
			return;
		}else{
			printf("\tTHOAT CHUONG TRINH !!!");
			printf("\n\t=========== CAM ON !! ===========");
			printf("\n\t======== HEN GAP LAI !! =========");
			exit(0);
			break;
		}
	}
	 
} 



