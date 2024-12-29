#include <stdio.h>
#include <string.h> 
#include"functions.h"
extern struct danhsach list[];
int a,b,i,j,mokhoa,thongtin; 
char khoa[10] = "mo";
int size = 5;



void start(int vitri){                         // giao dien 
	printf("vai tro cua ban ");
	printf("\n1. Quan ly ");
	printf("\n2.nguoi dung");
	printf ("\n3. thoat");
	printf("\n ban la: ");	
	scanf("%d",&vitri);
}

void account(int *a){  					// nhap tai khoan 
int stk;
int mk;
 do {
     printf("Tai khoan: ");
     scanf("%d",&stk); 
		getchar(); 
        printf("Mat khau: ");
        scanf("%d",&mk);
		getchar(); 
        if (stk==mk) {
            printf("Dang nhap thanh cong\n");
            *a = 1; 
            break;   
        } else {
            printf("Tai khoan hoac mat khau khong dung. Vui long thu lai.\n");
            *a = 0;  
        }
    } while (*a == 0); 
	
}

void hienthi(){	
		printf("Danh sach khach hang:\n");
        for ( i = 0; i < size; i++) {
            if (list[i].id == 0) {
                printf("Khong co du lieu tai vi tri %d.\n", i);
                continue; 
            }
            printf("ID: %d | Ten: %s |  SDT: %s | Trang thai: %s\n",
            list[i].id, list[i].name, list[i].sdt, list[i].khoa);
        }
	}
	
void timkiem(){
int tra;
do{
	printf("nhap id khach hang muon xem: ");
	scanf("%d",&thongtin);
	if(thongtin > 0 && thongtin < size){
			tra=1;
			printf(" khach hang chi tiet:\n");
		for(i = 0 ;i < size;i++){
    		if(thongtin == list[i].id){
    		printf("ID: %d | Ten: %s | So can cuoc: %s | Sinh nhat: %s/%s/%s | Gmail: %s | SDT: %s | Trang thai: %s\n",
            list[i].id, list[i].name, list[i].socancuoc,
			list[i].ngay, list[i].thang, list[i].nam,
			list[i].gmail, list[i].sdt, list[i].khoa);	
			}
		}
			}else{
			printf("khong co khach hang nao . xin nhap lai");
			tra=0;
			}	
	}while(a==0);
}

void themphantu(){
printf("so luong khanh hang muon them");
	scanf("%d",&b);
	for ( i = 0 ; i < b ; i++){
    printf("Nhap thong tin khach hang moi:\n");
    list[size].id = size + 1; 
    printf("ID: %d\n", list[size].id);
    printf("Name: ");
    getchar(); 
    fgets(list[size].name, sizeof(list[size].name), stdin);
    list[size].name[strcspn(list[size].name, "\n")] = 0;
    printf("So can cuoc: ");
    fgets(list[size].socancuoc, sizeof(list[size].socancuoc), stdin);
    list[size].socancuoc[strcspn(list[size].socancuoc, "\n")] = 0; 
    printf("ngay: ");
    fgets(list[size].ngay, sizeof(list[size].ngay), stdin);
    list[size].ngay[strcspn(list[size].ngay, "\n")] = 0;
    getchar();
    printf("thang: ");
    fgets(list[size].thang, sizeof(list[size].thang), stdin);
    list[size].thang[strcspn(list[size].thang, "\n")] = 0;
    getchar();
    printf("nam: ");
    fgets(list[size].nam, sizeof(list[size].nam), stdin);
    list[size].nam[strcspn(list[size].nam, "\n")] = 0;
    getchar();
    printf("gmail: ");
    fgets(list[size].gmail, sizeof(list[size].gmail), stdin);
    list[size].gmail[strcspn(list[size].gmail, "\n")] = 0;
    getchar();
    printf("SDT: ");
    fgets(list[size].sdt, sizeof(list[size].sdt), stdin);
    list[size].sdt[strcspn(list[size].sdt, "\n")] = 0;
    size++;
    printf("\nKhach hang da duoc them thanh cong!\n");
	
	}
}

void sapxep(){//loi
	for (i = 0; i < size - 1; i++) {  
        for (j = i; j < size; j++) {  
            if (strlen(list[j].name) < strlen(list[j + 1].name)) {
                struct danhsach temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    printf("da sap xep thanh cong");
    		hienthi();
}




void menuchoadmin(){
    do{
    printf("\n1.them khach hang");
    printf("\n2.hien thi ta ca khach hang");
    printf("\n3.hien thi chi tiet khach hang ");
    printf("\n4.khoa / mo khoa khach hang");
    printf("\n5.sap xep khach hang ");
    printf("\n6.luu thong tin khach hang");
    printf("\n7.thoat");
    printf("\nlua chon cua ban: ");
	scanf("%d",&a);
	switch(a){	
	case 1:// da xong 
	themphantu();
 		break;
	case 2 :// da xong // loi gmail
	hienthi();
		break;
	case 3: //loi gmail
	timkiem();
   		break;
	case 5 :// loi
 	sapxep();
	break;
	
//	case 6:
//		break:
	 case 7:
	 	printf("tam biet");
	 	break;
    }
	}while(a!= 7);				
}
