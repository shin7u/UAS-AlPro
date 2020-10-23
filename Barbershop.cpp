#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct menu{ //struct layanan
	char layanan[30];
	int harga;
}mn[4];

struct data{ //struct data pelanggan
	char nama[30];
	int pilihan1, pilihan2, pilihan3;
}dt;

awal(int &plh){ //function menu
	printf("\n\tCoba Barbershop\n");
	printf("--------------------------------\n");
	printf("1. Data Pelanggan\n");
	printf("2. Pilih Layanan\n");
	printf("3. Cetak Struk\n");
	printf("\nPilih menu: "); scanf("%d",&plh);
}

main()
{
	int plh,i,subtotal,diskon,total;
	char plh1,nama;
	
	strcpy(mn[1].layanan, "Potong Rambut");
	strcpy(mn[2].layanan, "Keramas");
	strcpy(mn[3].layanan, "Shaving");
	mn[1].harga = 15000;
	mn[2].harga = 10000;
	mn[3].harga = 5000;
	
	do{ //repeat menu awal
	awal(plh);
	switch(plh){
		case 1:{
			system("cls");
			printf("Tekan Enter setelah mengisi nama.\n");
			printf("\nNama: "); scanf("%s",&dt.nama);
			getche;
			break;
		}
		case 2:{
			if(!strcmp(dt.nama, "")){
				printf("Isi data pelanggan sebelum pilih layanan.\n");
				return main();
			}else{
			system("cls");
			printf("No. \tLayanan \tHarga\n");
			printf("--------------------------------\n");
			for(i=1;i<4;i++){
				printf("%i \t%s \tRp.%i\n",i ,mn[i].layanan, mn[i].harga);
			}
			printf("\nPilih semua? Y/N "); scanf("%s",&plh1);
			if(plh1=='y'){
				dt.pilihan1 = 1;
				dt.pilihan2 = 2;
				dt.pilihan3 = 3;
			}else if(plh1=='n'){
				printf("Untuk memilih 1 layanan saja, pilih '0' pada layanan yang ke-2.\n");
				printf("Pilih layanan: "); scanf("%d",&dt.pilihan1);
				printf("Pilih layanan: "); scanf("%d",&dt.pilihan2);
			}
			}
			break;
		}
		case 3:{
			if(!strcmp(dt.nama, "")){
				printf("Isi data pelanggan sebelum cetak struk.\n");
				return main();
			}else if(dt.pilihan1==0){
				printf("Pilih jenis layanan sebelum cetak struk.\n");
				return main();
			}else{
			system("cls");
			printf(" \tCoba Barbershop\n");
			printf("=================================\n");
			printf(" Nama: \t%s\n",dt.nama);
			printf(" No. \tLayanan \tHarga\n");
			if(dt.pilihan1==1){
				printf(" 1. \t%s \tRp.%d\n",mn[1].layanan,mn[1].harga);
			}else if(dt.pilihan1==2){
				printf(" 1. \t%s \tRp.%d\n",mn[2].layanan,mn[2].harga);
			}else if(dt.pilihan1==3){
				printf(" 1. \t%s \tRp.%d\n",mn[3].layanan,mn[2].harga);
			}
			if(dt.pilihan2==2){
				printf(" 2. \t%s \tRp.%d\n",mn[2].layanan,mn[2].harga);
			}else if(dt.pilihan2==3){
				printf(" 2. \t%s \tRp.%d\n",mn[3].layanan,mn[3].harga);
			}
			if(dt.pilihan3==3){
				printf(" 3. \t%s \tRp.%d\n",mn[3].layanan,mn[3].harga);
			}
			printf(".................................\n");
			subtotal=0;
			if(dt.pilihan1==1 && dt.pilihan2==2 && dt.pilihan3==3){
				for(i=1;i<4;i++){
					subtotal=subtotal+mn[i].harga;
				}
			}else if(dt.pilihan1==1 && dt.pilihan2==2){
				subtotal=mn[1].harga+mn[2].harga;
			}else if(dt.pilihan1==1 && dt.pilihan2==3){
				subtotal=mn[1].harga+mn[3].harga;
			}else if(dt.pilihan1==2 && dt.pilihan2==3){
				subtotal=mn[2].harga+mn[3].harga;
			}else if(dt.pilihan1==1 && dt.pilihan2==0){
				subtotal=mn[1].harga;
			}else if(dt.pilihan1==2 && dt.pilihan2==0){
				subtotal=mn[2].harga;
			}else if(dt.pilihan1==3 && dt.pilihan2==0){
				subtotal=mn[3].harga;
			}
			printf(" Subtotal: \t \tRp.%d\n",subtotal);
			diskon=0;
			if(dt.pilihan1==1 && dt.pilihan2==2 && dt.pilihan3==3){
				diskon=subtotal*0.05;
				printf(" Diskon: \t \tRp.%d\n",diskon);
			}else{
				printf(" Diskon: \t \tRp.0\n");
			}
			printf(".................................\n");
			total=subtotal-diskon;
			printf(" Total:  \t \tRp.%d\n",total);
			printf(".................................\n");
			printf("Terima kasih atas kunjungan anda\n");
			printf("---------------------------------\n");
			return 0;
			}
			break;
		}
		default:{
			printf("Input Invalid\n");
			return main();
		}
	}
	}while(plh<'1');
}

