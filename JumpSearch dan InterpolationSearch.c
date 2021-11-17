#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


struct buku{

    char judul_buku[50];
    char nama_pengarang[50];
    int kode;
    int convert_string;

}data_buku[10];

void JumpSearch();
void InterpolationSearch();

int main(){

    system("cls");
    //Data Buku 1
    strcpy(data_buku[0].judul_buku,"Wordpress Expert");
    strcpy(data_buku[0].nama_pengarang,"Andrew Octa");
    data_buku[0].kode = 101;
    data_buku[0].convert_string = 0;
    //Data Buku 2
    strcpy(data_buku[1].judul_buku,"C Programming");
    strcpy(data_buku[1].nama_pengarang,"James Lee");
    data_buku[1].kode = 3031;
    data_buku[1].convert_string = 0;
    //Data Buku 3
    strcpy(data_buku[2].judul_buku,"Web From Zero to Hero");
    strcpy(data_buku[2].nama_pengarang,"David Guetta");
    data_buku[2].kode = 8812;
    data_buku[2].convert_string = 0;
    //Data Buku 4
    strcpy(data_buku[3].judul_buku,"Codelgniter 4 the guide");
    strcpy(data_buku[3].nama_pengarang,"Gantz Patrick");
    data_buku[3].kode = 111;
    data_buku[3].convert_string = 0;
    //Data Buku 5
    strcpy(data_buku[4].judul_buku,"Master Flutter");
    strcpy(data_buku[4].nama_pengarang,"Ozur Haskels");
    data_buku[4].kode = 66;
    data_buku[4].convert_string = 0;
    //Data Buku 6
	strcpy(data_buku[5].judul_buku,"Laravel");
    strcpy(data_buku[5].nama_pengarang,"Hans Jackson");
    data_buku[5].kode = 790;
    data_buku[5].convert_string = 0;
    //Data Buku 7
    strcpy(data_buku[6].judul_buku,"Raspberry Pi 4");
    strcpy(data_buku[6].nama_pengarang,"Tony Watts");
    data_buku[6].kode = 678;
    data_buku[6].convert_string = 0;
    //Data Buku 8
    strcpy(data_buku[7].judul_buku,"Building Robotic AI");
    strcpy(data_buku[7].nama_pengarang,"Leni Imelda");
    data_buku[7].kode = 901;
    data_buku[7].convert_string = 0;
    //Data Buku 9
    strcpy(data_buku[8].judul_buku,"Go Lang Introduction");
    strcpy(data_buku[8].nama_pengarang,"Brian Macakzie");
    data_buku[8].kode = 4089;
    data_buku[8].convert_string = 0;
    //Data Buku 10
    strcpy(data_buku[9].judul_buku,"Data Science With Python");
    strcpy(data_buku[9].nama_pengarang,"Ranya Sundar");
    data_buku[9].kode = 303;
    data_buku[9].convert_string = 0;

    int pilih, i;
    int length = sizeof(data_buku)/sizeof(data_buku[0]);
    
    printf("\t\t==================================================================\n");
    printf("\t\t========== Muhammad Fadhil Fakhrusyakirin - 20081010216===========\n");
    printf("\t\t==================================================================\n");
    
    menu:
    printf("\t\t==============================Menu================================\n");
    printf("\t\t[1]. Melihat Data Buku\n");
    printf("\t\t[2]. Search Data Judul (Metode Interpolation Search)\n");
    printf("\t\t[3]. Search Data kode buku (Metode Jump Search)\n");
    printf("\t\t[4]. Keluar Aplikasi \n ");
    printf("\t\t==================================================================\n");
    printf("\t\tMasukkan Pilihan Anda : ");
    scanf("%i",&pilih);
    
    switch (pilih){
    case 1:
        for ( i = 0; i < length; i++){
        	printf("\t\tData ke-%i\n",i+1);
        	printf("\t\t=================Data Buku=================\n");
        	printf("\t\tJudul buku\t: %s\n",data_buku[i].judul_buku);
        	printf("\t\tNama Pengarang\t: %s\n",data_buku[i].nama_pengarang);
            printf("\t\tKode pada Buku\t: %i\n",data_buku[i].kode);
            printf("\t\t===========================================\n");
        }
        
		goto menu;
        break;
    
    case 2:
        
        InterpolationSearch();
        system("pause");
        main();
        break;

    case 3:

        JumpSearch();
        system("pause");
		main();
        break;
	
	case 4:
		printf("\t\tTerima Kasih");
	 break;
	 
    default:
        printf("\t\tInputan Salah\n");
        break;
    }

    return 0;
}

void InterpolationSearch(){
    
    int i,h,x,s;
    int a = sizeof(data_buku)/sizeof(data_buku[0]);
    int length[a];

    for ( i = 0; i < a; i++){
        length[i] = strlen(data_buku[i].judul_buku);
        
        for ( s = 0; s < length[i]; s++){
            data_buku[i].convert_string += data_buku[i].judul_buku[s];
        }
    }
    
    for ( h = 0; h < 10; h++){
        int temp,temp1;
        char temp2[50],temp3[50];
        temp = data_buku[h].convert_string;
        temp1 = data_buku[h].kode;
        strcpy(temp2,data_buku[h].judul_buku);
        strcpy(temp3,data_buku[h].nama_pengarang);
        x = h-1;
            while (x>=0 && data_buku[x].convert_string > temp){
                strcpy(data_buku[x+1].judul_buku,data_buku[x].judul_buku);
                strcpy(data_buku[x+1].nama_pengarang,data_buku[x].nama_pengarang);
                data_buku[x+1].kode = data_buku[x].kode;
                data_buku[x+1].convert_string = data_buku[x].convert_string;
                x = x-1;
            }
        strcpy(data_buku[x+1].judul_buku,temp2);
        strcpy(data_buku[x+1].nama_pengarang,temp3);
        data_buku[x+1].kode = temp1;
        data_buku[x+1].convert_string = temp;
    }


    char string_cari[50];
    int convert_string = 0;
    printf("\t\nMasukkan Judul Buku : ");
    fflush(stdin); gets(string_cari);

    int panjang = strlen(string_cari);
    for ( i = 0; i < panjang; i++){
        convert_string += string_cari[i];
    }
    
    int low = 0;
    int high = a - 1;
    int position;
    int status = 0;

    while (low <= high){

        position = low+((convert_string-data_buku[low].convert_string)/(data_buku[high].convert_string-data_buku[low].convert_string))*(high - low);
        
        if(data_buku[position].convert_string == convert_string){
            printf("\t\tData Ditemukan ");
            printf("\n========================================================\n");
            printf("\t\tJudul\t\t: %s\n",data_buku[position].judul_buku);
            printf("\t\tPengarang\t: %s\n",data_buku[position].nama_pengarang);
            printf("\t\tKode Buku\t: %i\n",data_buku[position].kode);
            printf("==========================================================\n");
            status = 1;
            break;
        }else if(data_buku[position].convert_string > convert_string){
            high = position - 1;
        }else{
            low = position + 1;
        }
    }
    if (status == 0){
            printf("\t\t\nData tidak Ditemukan! \n");
        }
}

void JumpSearch(){
    
    int cari;
    printf("\nMasukkan Kode Buku yang ingin dicari : ");
    scanf("%d", &cari);

    int h,x;
    int length = sizeof(data_buku)/sizeof(data_buku[0]);
    int jump = sqrt(length);
    int jumper = jump;
    

    for ( h = 0; h < 10; h++){
        int temp;
        char temp1[50],temp2[50];
        strcpy(temp1,data_buku[h].judul_buku);
        strcpy(temp2,data_buku[h].nama_pengarang);
        temp = data_buku[h].kode;
        x = h-1;
            while (x>=0 && data_buku[x].kode > temp){
                strcpy(data_buku[x+1].judul_buku,data_buku[x].judul_buku);
                strcpy(data_buku[x+1].nama_pengarang,data_buku[x].nama_pengarang);
                data_buku[x+1].kode = data_buku[x].kode;
                x = x-1;
            }
        strcpy(data_buku[x+1].judul_buku,temp1);
        strcpy(data_buku[x+1].nama_pengarang,temp2);
        data_buku[x+1].kode = temp;
    }

    int prev = 0;
    while (data_buku[jumper].kode <= cari && jumper < length){
        
        prev = jump;
        jumper+=jump;
        
    }
    
    int status = 0,i;
    for (i = prev; i <= jumper; i++){
        if (data_buku[i].kode == cari){
            status = 1;
            printf("Data Ditemukan\n");
            printf("===============================================\n");
            printf("Judul\t\t: %s\n",data_buku[i].judul_buku);
            printf("Pengarang\t: %s\n",data_buku[i].nama_pengarang);
            printf("Kode Buku\t: %i\n",data_buku[i].kode);
            printf("===============================================\n");
        }
    }
    if (status == 0){
        printf("\nData tidak ketemu :(\n");
        printf("Coba lagi dengan kode yang benar!\n");
    }

}
