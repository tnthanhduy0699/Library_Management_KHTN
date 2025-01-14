#include <stdio.h>
#include <string.h>
#include "Sach.h"

//7.  Xem danh sach cac sach trong thu vien
void XemSach(int bookISBN[], char bookName[][MaxNameLen], char authName[][MaxNameLen], char Publisher[MaxBook][MaxNameLen], int PublishYear[MaxBook], char bookType[MaxBook][MaxNameLen], int bookPrice[MaxBook], int bookAmount[], int bookCount)
{
	//Kiem tra so luong sach hien tai
	if (bookCount == 0)
	{
		printf("Hien tai chua co quyen sach nao trong thu vien!\n");
		return;
	}

	printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+--------------+---------------+\n");
	printf("|    No.   |         Ten sach         |       Ten tac gia        |       Nha xuat ban       | Nam xuat ban |       The loai        |   Gia sach   | So luong sach |\n");
	printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+------------------------------+\n");

	for (int i = 0; i < bookCount; i++)
	{
		printf("| %03d      | %-25s| %-24s | %-24s | %4d         | %-21s | %06d VND   | %03d quyen     |\n",
		bookISBN[i],
		bookName[i],
		authName[i],
		Publisher[i],
		PublishYear[i],
		bookType[i],
		bookPrice[i],
		bookAmount[i]);
	}
	printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+--------------+---------------+\n");
}
//8.  Them sach
int ThemSach(int bookISBN[], char bookName[][MaxNameLen], char authName[][MaxNameLen], char Publisher[MaxBook][MaxNameLen], int PublishYear[MaxBook], char bookType[MaxBook][MaxNameLen], int bookPrice[MaxBook], int bookAmount[], int bookCount)
{
	//Kiem tra so luong sach hien tai
	if (bookCount >= MaxBook)
	{
		printf("So luong sach da day. Khong the them sach duoc nua!\n");
		return 0;
	}
	
	printf("Nhap ma sach: ");
	scanf("%d", &bookISBN[bookCount]);

	printf("Nhap ten sach: ");
	getchar();
	fgets(bookName[bookCount], MaxNameLen, stdin);
	//Xoa dau "\n" xuong dong
	bookName[bookCount][strcspn(bookName[bookCount], "\n")] = '\0';

	printf("Nhap ten tac gia sach: ");
	fgets(authName[bookCount], MaxNameLen, stdin);
	//Xoa dau "\n" xuong dong
	authName[bookCount][strcspn(authName[bookCount], "\n")] = '\0';

	printf("Nhap ten nha xuat ban: ");
	fgets(Publisher[bookCount], MaxNameLen, stdin);
	//Xoa dau "\n" xuong dong
	Publisher[bookCount][strcspn(Publisher[bookCount], "\n")] = '\0';
	//Nhap nam xuat ban, nam xuat ban khong them lon hon 2024
	do
	{
		printf("Nhap nam xuat ban: ");
		scanf("%d", &PublishYear[bookCount]);
		if (PublishYear[bookCount] > 2024)
		{
			printf("Nam xuat ban sach khong hop le. Vui long nhap lai!\n");
		}
		
	} while (PublishYear[bookCount] > 2024);

	printf("Nhap the loai sach: ");
	getchar();
	fgets(bookType[bookCount], MaxNameLen, stdin);
	//Xoa dau "\n" xuong dong
	bookType[bookCount][strcspn(bookType[bookCount], "\n")] = '\0';

	printf("Nhap gia tien cua sach: ");
	scanf("%d", &bookPrice[bookCount]);

	printf("Nhap so luong sach: ");
	scanf("%d", &bookAmount[bookCount]);

	bookCount++;
	printf("Them sach thanh cong!\n");

	return bookCount;
}
//9. chinh sua thong tin sach
void ChinhSuaThongTinSach(int bookISBN[], char bookName[][MaxNameLen], char authName[][MaxNameLen], char Publisher[MaxBook][MaxNameLen], int PublishYear[MaxBook], char bookType[MaxBook][MaxNameLen], int bookPrice[MaxBook], int bookAmount[], int bookCount)
{
	//Kiem tra so luong sach hien tai
	if (bookCount == 0)
	{
		printf("Chua co sach trong thu vien. Vui long them thong tin sach truoc khi chinh sua!\n");
		return;
	}

	int bookindex;
	printf("Nhap so thu tu sach can chinh sua: ");
	scanf("%d", &bookindex);

	if (bookindex < 0 || bookindex - 1 > bookCount - 1)
	{
		printf("Khong ton quyen sach nay!\n");
		return;
	}

	int bookchoice;
	printf("Cac thong tin co the chinh sua: \n");
	printf("1. Ma sach (No.)\n");
	printf("2. Ten sach\n");
	printf("3. Ten tac gia\n");
	printf("4. Ten nha xuat ban\n");
	printf("5. Nam xuat ban\n");
	printf("6. Loai sach\n");
	printf("7. Gia tien\n");
	printf("8. So luong sach\n");
	printf("Chon thong tin can chinh sua: ");
	scanf("%d", &bookchoice);
	switch (bookchoice)
	{
	case 1:
		//Chinh sua ma sach
		printf("Nhap ma sach moi: ");
		scanf("%d", &bookISBN[bookindex-1]);
		printf("Cap nhat ma sach thanh cong!\n");
		break;
	case 2:
		//Chinh sua ten sach
		printf("Nhap ten sach moi: ");
		getchar();
		fgets(bookName[bookindex-1], MaxNameLen, stdin);
		bookName[bookindex-1][strcspn(bookName[bookindex-1], "\n")] = '\0';
		printf("Cap nhat ten sach thanh cong!\n");
		break;
	case 3:
		//Chinh sua ten tac gia
		printf("Nhap ten tac gia moi: ");
		getchar();
		fgets(authName[bookindex-1], MaxNameLen, stdin);
		authName[bookindex-1][strcspn(authName[bookindex-1], "\n")] = '\0';
		printf("Cap nhat ten tac gia thanh cong!\n");
		break;
	case 4:
		//Chinh sua ten nha xuat ban
		printf("Nhap ten nha xuat ban moi: ");
		getchar();
		fgets(Publisher[bookindex-1], MaxNameLen, stdin);
		Publisher[bookindex-1][strcspn(Publisher[bookindex-1], "\n")] = '\0';
		printf("Cap nhat ten nha xuat ban thanh cong!\n");
		break;
	case 5:
		//Chinh sua nam xuat ban sach
		printf("Nhap nam xuat ban moi: ");
		scanf("%d", &PublishYear[bookindex-1]);
		printf("Cap nhat nam xuat ban thanh cong!\n");
		break;
	case 6:
		//Chinh sua the loai sach
		printf("Nhap the loai sach moi: ");
		getchar();
		fgets(bookType[bookindex-1], MaxNameLen, stdin);
		bookType[bookindex-1][strcspn(bookType[bookindex-1], "\n")] = '\0';
		printf("Cap nhat the loai sach thanh cong!\n");
		break;
	case 7:
		//Chinh sua gia tien cua sach
		printf("Nhap gia tien moi: ");
		scanf("%d", &bookPrice[bookindex-1]);
		printf("Cap nhat lai gia tien cua sach thanh cong!\n");
		break;
	case 8:
		//Chinh sua so luong sach
		printf("Nhap lai so luong sach: ");
		scanf("%d", &bookAmount[bookindex-1]);
		printf("Cap nhat lai so luong sach thanh cong!\n");
		break;
	default:
		printf("Khong ton tai thong tin nay!\n");
		break;
	}
}
//10. Xoa sach
int XoaSach(int bookISBN[], char bookName[][MaxNameLen], char authName[][MaxNameLen], char Publisher[MaxBook][MaxNameLen], int PublishYear[MaxBook], char bookType[MaxBook][MaxNameLen], int bookPrice[MaxBook], int bookAmount[], int bookCount)
{
	//Kiem tra so luong sach hien tai
	if (bookCount == 0)
	{
		printf("Chua co sach trong thu vien. Vui long them thong tin sach truoc khi xoa!\n");
		return 0;
	}

	int bookpos;
	printf("Nhap vi tri sach can xoa: ");
	scanf("%d", &bookpos);
	//Xet dieu kien cua pos sau khi nhap
	if (bookpos < 0 || bookpos - 1 > bookCount - 1)
	{
		printf("Khong ton tai doc gia nay!\n");
		return 0;
	}

	for (int i = bookpos - 1; i < bookCount - 1; i++)
	{
		bookISBN[i] = bookISBN[i + 1];
		strcpy(bookName[i], bookName[i + 1]);
		strcpy(authName[i], authName[i + 1]);
		strcpy(Publisher[i], Publisher[i + 1]);
		PublishYear[i] = PublishYear[i + 1];
		strcpy(bookType[i], bookType[i + 1]);
		bookPrice[i] = bookPrice[i + 1];
		bookAmount[i] = bookAmount[i + 1];
	}
	// Giam so luong sach
	bookCount--;

	printf("Da xoa sach khoi thu vien!\n");
	return bookCount;
}
//11. Tim kiem sach theo ISBN
void TimKiemSach_ISBN(int bookISBN[], char bookName[][MaxNameLen], char authName[][MaxNameLen], char Publisher[MaxBook][MaxNameLen], int PublishYear[MaxBook], char bookType[MaxBook][MaxNameLen], int bookPrice[MaxBook], int bookAmount[], int bookCount)
{
	int bookfound = 0;
	int searchBookISBN;
	//Kiem tra so luong sach hien tai
	if (bookCount == 0)
	{
		printf("Hien tai chua co quyen sach nao trong thu vien!\n");
		return;
	}

	printf("Nhap ISBN can tim: ");
	scanf("%d", &searchBookISBN);

	for (int i = 0; i < bookCount; i++)
	{
		if (bookISBN[i] == searchBookISBN)
		{
			if (bookfound == 0)
			{
				printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+--------------+---------------+\n");
				printf("|    No.   |         Ten sach         |       Ten tac gia        |       Nha xuat ban       | Nam xuat ban |       The loai        |   Gia sach   | So luong sach |\n");
				printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+------------------------------+\n");
			}
			printf("| %03d      | %-25s| %-24s | %-24s | %4d         | %-21s | %06d VND   | %03d quyen     |\n",
			bookISBN[i],
			bookName[i],
			authName[i],
			Publisher[i],
			PublishYear[i],
			bookType[i],
			bookPrice[i],
			bookAmount[i]);
			//Tang so luong sach neu tim duoc sach
			bookfound++;
		}
	}
	
	if (bookfound == 0)
	{
		printf("Khong tim thay sach co ISBN: %d trong thu vien", searchBookISBN);
	}
	else
	{
		printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+--------------+---------------+\n");
		if (bookfound >= 2)
		{
			printf("Da tim thay %d quyen sach co cung ISBN\n", bookfound);
		}
		else
		{
			printf("Da tim thay %d quyen sach\n", bookfound);
		}
	}
}
//12. Tim kiem sach theo ten sach
void TimKiemSach_TenSach(int bookISBN[], char bookName[][MaxNameLen], char authName[][MaxNameLen], char Publisher[MaxBook][MaxNameLen], int PublishYear[MaxBook], char bookType[MaxBook][MaxNameLen], int bookPrice[MaxBook], int bookAmount[], int bookCount)
{
	int bookfound = 0;
	char searchBookName[MaxNameLen];
	//Kiem tra so luong sach hien tai
	if (bookCount == 0)
	{
		printf("Hien tai chua co quyen sach nao trong thu vien!\n");
		return;
	}

	printf("Nhap ten sach can tim: ");
	getchar();
	fgets(searchBookName, MaxNameLen, stdin);
	searchBookName[strcspn(searchBookName, "\n")] = '\0';

	for (int i = 0; i < bookCount; i++)
	{
		if (strcmp(bookName[i], searchBookName) == 0)
		{
			if (bookfound == 0)
			{
				printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+--------------+---------------+\n");
				printf("|    No.   |         Ten sach         |       Ten tac gia        |       Nha xuat ban       | Nam xuat ban |       The loai        |   Gia sach   | So luong sach |\n");
				printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+------------------------------+\n");
			}
			printf("| %03d      | %-25s| %-24s | %-24s | %4d         | %-21s | %06d VND   | %03d quyen     |\n",
			bookISBN[i],
			bookName[i],
			authName[i],
			Publisher[i],
			PublishYear[i],
			bookType[i],
			bookPrice[i],
			bookAmount[i]);
			//Tang so luong sach neu tim duoc sach
			bookfound++;
		}
	}
	
	if (bookfound == 0)
	{
		printf("Khong tim thay sach \"%s\" trong thu vien", searchBookName);
	}
	else
	{
		printf("+----------+--------------------------+--------------------------+--------------------------+--------------+-----------------------+--------------+---------------+\n");
		if (bookfound >= 2)
		{
			printf("Da tim thay %d quyen sach co cung ten\n", bookfound);
		}
		else
		{
			printf("Da tim thay %d quyen sach\n", bookfound);
		}
	}
}
//15. Thong ke so luong sach trong thu vien
void ThongKeSoLuongSach(int bookISBN[], char bookName[][MaxNameLen], char authName[][MaxNameLen], char Publisher[MaxBook][MaxNameLen], int PublishYear[MaxBook], char bookType[MaxBook][MaxNameLen], int bookPrice[MaxBook], int bookAmount[], int bookCount)
{
	//Kiem tra so luong sach hien ta
	if (bookCount == 0)
	{
		printf("Hien tai chua co quyen sach nao trong thu vien!\n");
		return;
	}
	
	printf("So luong sach hien tai: %d quyen\n", bookCount);

	//Goi lai ham XemSach de in ra so luong sach duoi dang bang thong ke
	XemSach(bookISBN, bookName, authName, Publisher, PublishYear, bookType, bookPrice, bookAmount, bookCount);
}
//16. Thong ke sach theo the loai
void ThongKeSachTheoTheLoai(char bookType[][MaxNameLen], int bookCount)
{
	int duplicateTypeAmount[MaxBook] = {0}; //Mang dem so luong sach cua 1 the loai
	char duplicateType[MaxBook][MaxNameLen]; //Mang luu ten cac the loai
	int TypeCount = 0; //Mang luu so luong cac the loai, neu trung thi mang van = 0
	
	//Duyet qua tung quyen sach trong thu vien
	for (int i = 0; i < bookCount; i++)
	{
		//found luon bang 0 o dau moi vong lap de bat dau kiem tra lai tu dau moi khi qua 1 sach moi
		int found = 0;
		for (int j = 0; j < TypeCount; j++)
		{
			if (strcmp(bookType[i], duplicateType[j]) == 0)
			{
				duplicateTypeAmount[j]++;
				found = 1;
				break;
			}
			
		}
		
		//Neu found van bang 0, loai sach chua ton tai trong mang Type => Them loai sach vao mang duplicateType, tang duplicateTypeAmount, tang TypeCount
		if (found == 0)
		{
			strcpy(duplicateType[TypeCount], bookType[i]); //Them the loai sach vao mang chua cac kieu sach
			duplicateTypeAmount[TypeCount] = 1; //Tang so luong len 1 sau khi tang
			TypeCount++; //Tang loai sach len để 
		}
	}
	
	printf("Bang thong ke: \n");
	printf("+-----------------------+---------------+\n");
	printf("|       The loai        | So luong sach |\n");
	printf("+-----------------------+---------------+\n");
	for (int i = 0; i < TypeCount; i++)
	{
		printf("| %-21s | %03d quyen     |\n", duplicateType[i], duplicateTypeAmount[i]);
	}
	printf("+-----------------------+---------------+\n");
}