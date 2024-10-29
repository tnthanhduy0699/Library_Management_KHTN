#include <stdio.h>
#include <string.h>
#include "DocGia.h"

//1.  Xem danh sach doc gia trong thu vien
void XemDocGia(int readerNo[], char readerName[][MaxNameLen], char readerID[][MaxNameLen], int readerDate[], int readerMonth[], int readerYear[], char readerGender[][MaxNameLen], char readerEmail[MaxReader][MaxNameLen], char readerLocation[][MaxNameLen], int libraryCardDate[], int libraryCardMonth[], int libraryCardYear[], int readerCount)
{
	//Kiem tra so luong doc gia hien tai
	if (readerCount == 0)
	{
		printf("Hien tai chua co doc gia nao!\n");
		return;
	}

	printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");
	printf("|    No.   |      Ho ten doc gia      |     CCCD      | Ngay thang nam sinh | Gioi tinh |           Email           |    Dia chi    |  Ngay lap the  |\n");
	printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");
	for (int i = 0; i < readerCount; i++)
	{
		printf("| %03d      | %-25s| %-13s | %02d / %02d / %04d      | %-9s | %-25s | %-13s | %02d / %02d / %04d |\n",
		readerNo[i],
		readerName[i],
		readerID[i],
		readerDate[i],
		readerMonth[i],
		readerYear[i],
		readerGender[i],
		readerEmail[i],
		readerLocation[i],
		libraryCardDate[i],
		libraryCardMonth[i],
		libraryCardYear[i]);
	}
	printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");

}
//2.  Them doc gia
int ThemDocGia(int readerNo[], char readerName[][MaxNameLen], char readerID[][MaxNameLen], int readerDate[], int readerMonth[], int readerYear[], char readerGender[][MaxNameLen], char readerEmail[MaxReader][MaxNameLen], char readerLocation[][MaxNameLen], int libraryCardDate[], int libraryCardMonth[], int libraryCardYear[], int readerCount)
{
	//Kiem tra so luong doc gia hien tai
	if (readerCount >= MaxReader)
	{
		printf("Khong the them doc gia nua!\n");
		return 0;
	}
	
	printf("Nhap ma doc gia: ");
	scanf("%d", &readerNo[readerCount]);

	printf("Nhap ho ten doc gia: ");
	getchar();
	fgets(readerName[readerCount], MaxNameLen, stdin);
	//Xoa dau "\n" xuong dong
	readerName[readerCount][strcspn(readerName[readerCount], "\n")] = '\0';

    printf("Nhap CCCD cua doc gia: ");
	fgets(readerID[readerCount], MaxNameLen, stdin);
	readerID[readerCount][strcspn(readerID[readerCount], "\n")] = '\0';

	printf("Nhap ngay, thang, nam sinh: ");
	scanf("%d %d %d", &readerDate[readerCount], &readerMonth[readerCount], &readerYear[readerCount]);

    printf("Nhap gioi tinh: ");
    getchar();
    fgets(readerGender[readerCount], MaxNameLen, stdin);
	readerGender[readerCount][strcspn(readerGender[readerCount], "\n")] = '\0';

    printf("Nhap email: ");
    fgets(readerEmail[readerCount], MaxNameLen, stdin);
	readerEmail[readerCount][strcspn(readerEmail[readerCount], "\n")] = '\0';

	//Chi nhap dia chi la thanh pho lon
    printf("Nhap dia chi (Thanh pho): ");
    fgets(readerLocation[readerCount], MaxNameLen, stdin);
	readerLocation[readerCount][strcspn(readerLocation[readerCount], "\n")] = '\0';

	printf("Nhap ngay, thang, nam tao the thu vien: ");
	scanf("%d %d %d", &libraryCardDate[readerCount], &libraryCardMonth[readerCount], &libraryCardYear[readerCount]);

	readerCount++;
	printf("Them doc gia thanh cong!\n");
	return readerCount;
}
//3.  Chinh sua thong tin mot doc gia
void ChinhSuaThongTinDocGia(int readerNo[], char readerName[][MaxNameLen], char readerID[][MaxNameLen], int readerDate[], int readerMonth[], int readerYear[], char readerGender[][MaxNameLen], char readerEmail[MaxReader][MaxNameLen], char readerLocation[][MaxNameLen], int libraryCardDate[], int libraryCardMonth[], int libraryCardYear[], int readerCount)
{
	//Kiem tra so luong doc gia hien tai
	if (readerCount == 0)
	{
		printf("Chua co doc gia. Vui long them thong tin doc gia truoc khi chinh sua!\n");
		return;
	}

	int index;
	printf("Nhap so thu tu doc gia can chinh sua: ");
	scanf("%d", &index);

	if (index < 0 || index > readerCount - 1)
	{
		printf("Khong ton tai doc gia nay!\n");
		return;
	}

	int choice;
	printf("Cac thong tin co the chinh sua: \n");
	printf("1. Ma doc gia\n");
	printf("2. Ho ten\n");
	printf("3. So CMND\n");
	printf("4. Ngay, thang, nam sinh\n");
	printf("5. Gioi tinh\n");
	printf("6. Email\n");
	printf("7. Dia chi\n");
	printf("8. Ngay lap the muon sach\n");
	printf("Chon thong tin can chinh sua: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		//Chinh sua ID
		printf("Nhap ma doc gia moi:");
		scanf("%d", &readerNo[index]);
		printf("Cap nhat lai ma doc gia thanh cong!\n");
		break;
	case 2:
		//Chinh sua ho ten
		printf("Nhap ho ten doc gia moi: ");
		getchar();
		fgets(readerName[index], MaxNameLen, stdin);
		readerName[index][strcspn(readerName[index], "\n")] = '\0';
		printf("Cap nhat lai ho ten doc gia thanh cong!\n");
		break;
	case 3:
		//Chinh sua so CCCD
		printf("Nhap CCCD cua doc gia: ");
		getchar();
		fgets(readerID[index], MaxNameLen, stdin);
		readerID[index][strcspn(readerID[index], "\n")] = '\0';
		printf("Cap nhat lai so CCCD thanh cong!\n");
		break;
	case 4:
		//Chinh sua ngay thang nam sinh
		printf("Nhap ngay, thang, nam sinh moi: ");
		scanf("%d %d %d", &readerDate[index], &readerMonth[index], &readerYear[index]);
		printf("Cap nhat ngay, thang, nam sinh thanh cong!\n");
		break;
	case 5:
		//Chinh sua gioi tinh
		printf("Nhap lai gioi tinh: ");
		getchar();
		fgets(readerGender[index], MaxNameLen, stdin);
		readerGender[index][strcspn(readerGender[index], "\n")] = '\0';
		printf("Cap nhat lai gioi tinh thanh cong!\n");
		break;
	case 6:
		//Chinh sua email
		printf("Nhap email moi: ");
		getchar();
		fgets(readerEmail[index], MaxNameLen, stdin);
		readerEmail[index][strcspn(readerEmail[index], "\n")] = '\0';
		printf("Cap nhat lai email thanh cong!\n");
		break;
	case 7:
		//Chinh sua dia chi
		printf("Nhap ngay, thang, nam sinh moi: ");
		getchar();
		fgets(readerLocation[index], MaxNameLen, stdin);
		readerLocation[index][strcspn(readerLocation[index], "\n")] = '\0';
		printf("Cap nhat lai dia chi thanh cong!\n");
		break;
	case 8:
		//Chinh sua ngay lap the muon sach
		printf("Nhap ngay, thang, nam lap the muon sach moi: ");
		scanf("%d %d %d", &libraryCardDate[index], &libraryCardMonth[index], &libraryCardYear[index]);
		printf("Cap nhat lai ngay, thang, nam lap the muon sach thanh cong!\n");
		break;
	default:
		printf("Khong ton tai thong tin nay!\n");
		break;
	}
}
//4.  Xoa thong tin mot doc gia
int XoaDocGia(int readerNo[], char readerName[][MaxNameLen], char readerID[][MaxNameLen], int readerDate[], int readerMonth[], int readerYear[], char readerGender[][MaxNameLen], char readerEmail[MaxReader][MaxNameLen], char readerLocation[][MaxNameLen], int libraryCardDate[], int libraryCardMonth[], int libraryCardYear[], int readerCount)
{
	int pos;
	printf("Nhap vi tri doc gia can xoa: ");
	scanf("%d", &pos);

	for (int i = pos; i < readerCount - 1; i++)
	{
		readerNo[i] = readerNo[i + 1];
		strcpy(readerName[i], readerName[i + 1]);
		strcpy(readerID[i], readerID[i + 1]);
		readerDate[i] = readerDate[i + 1];
		readerMonth[i] = readerMonth[i + 1];
		readerYear[i] = readerYear[i + 1];
		strcpy(readerGender[i], readerGender[i + 1]);
		strcpy(readerEmail[i], readerEmail[i + 1]);
		strcpy(readerLocation[i], readerLocation[i + 1]);
		libraryCardDate[i] = libraryCardDate[i + 1];
		libraryCardMonth[i] = libraryCardMonth[i + 1];
		libraryCardYear[i] = libraryCardYear[i + 1];
	}

	// Giam so luong doc gia
	readerCount--;

	printf("Da xoa doc gia khoi danh sach!\n");
	return readerCount;
}
//5. Tim kiem doc gia theo CCCD
void TimKiemDocGia_CCCD(int readerNo[], char readerName[][MaxNameLen], char readerID[][MaxNameLen], int readerDate[], int readerMonth[], int readerYear[], char readerGender[][MaxNameLen], char readerEmail[MaxReader][MaxNameLen], char readerLocation[][MaxNameLen], int libraryCardDate[], int libraryCardMonth[], int libraryCardYear[], int readerCount)
{
	int found = 0;
	char searchCCCD[MaxNameLen];
	//Kiem tra so luong doc gia hien tai
	if (readerCount == 0)
	{
		printf("Hien tai chua co doc gia nao!\n");
		return;
	}

	printf("Nhap so CCCD cua doc gia can tim: ");
	getchar();
	fgets(searchCCCD, MaxNameLen, stdin);
	searchCCCD[strcspn(searchCCCD, "\n")] = '\0';

	for (int i = 0; i < readerCount; i++)
	{
		if (strcmp(readerID[i], searchCCCD) == 0)
		{
			if (found == 0)
			{
				printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");
				printf("|    No.   |      Ho ten doc gia      |     CCCD      | Ngay thang nam sinh | Gioi tinh |           Email           |    Dia chi    |  Ngay lap the  |\n");
				printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");
			}
			
			printf("| %03d      | %-25s| %-13s | %02d / %02d / %04d      | %-9s | %-25s | %-13s | %02d / %02d / %04d |\n",
			readerNo[i],
			readerName[i],
			readerID[i],
			readerDate[i],
			readerMonth[i],
			readerYear[i],
			readerGender[i],
			readerEmail[i],
			readerLocation[i],
			libraryCardDate[i],
			libraryCardMonth[i],
			libraryCardYear[i]);
			//Tang so luong doc gia neu tim duoc doc gia
			found++;
		}
	}

	if (!found)
	{
		printf("Khong tim thay doc gia co so CCCD: \"%s\" trong danh sach\n", searchCCCD);
	}
	else
	{
		printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");
		if (found >= 2)
		{
			printf("Da tim thay %d doc gia cung so CCCD\n", found);

		}
		else
		{
			printf("Da tim thay %d doc gia\n", found);
		}
	}
}
//6. Tim kiem doc gia theo ho ten
void TimKiemDocGia_Ten(int readerNo[], char readerName[][MaxNameLen], char readerID[][MaxNameLen], int readerDate[], int readerMonth[], int readerYear[], char readerGender[][MaxNameLen], char readerEmail[MaxReader][MaxNameLen], char readerLocation[][MaxNameLen], int libraryCardDate[], int libraryCardMonth[], int libraryCardYear[], int readerCount)
{
	int found = 0;
	char searchName[MaxNameLen];

	if (readerCount == 0)
	{
		printf("Hien tai chua co doc gia nao!\n");
		return;
	}

	printf("Nhap ho ten doc gia can tim: ");
	getchar();
	fgets(searchName, MaxNameLen, stdin);
	searchName[strcspn(searchName, "\n")] = '\0';

	for (int i = 0; i < readerCount; i++)
	{
		if (strcmp(readerName[i], searchName) == 0)
		{
			if (found == 0)
			{
				printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");
				printf("|    ID    |      Ho ten doc gia      |      CCCD     | Ngay thang nam sinh | Gioi tinh |           Email           |    Dia chi    |  Ngay lap the  |\n");
				printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");
			}
			
			printf("|  %04d    | %-25s| %-13s | %02d / %02d / %04d      | %-9s | %-25s | %-13s | %02d / %02d / %04d |\n",
			readerNo[i],
			readerName[i],
			readerID[i],
			readerDate[i],
			readerMonth[i],
			readerYear[i],
			readerGender[i],
			readerEmail[i],
			readerLocation[i],
			libraryCardDate[i],
			libraryCardMonth[i],
			libraryCardYear[i]);
			
			found++;
		}
	}

	if (!found)
	{
		printf("Khong tim thay doc gia \"%s\" trong danh sach\n", searchName);
	}
	else
	{
		printf("+----------+--------------------------+---------------+---------------------+-----------+---------------------------+---------------+----------------+\n");
		if (found >= 2)
		{
			printf("Da tim thay %d doc gia co cung ten\n", found);

		}
		else
		{
			printf("Da tim thay %d doc gia\n", found);
		}
	}
}
//17. Thong ke so luong doc gia
int ThongKeSoLuongDocGia(int readerCount)
{
	if (readerCount == 0)
	{
		printf("Hien tai chua co doc gia nao!\n");
		return 0;
	}
	printf("So luong doc gia hien tai: %d nguoi\n", readerCount);
	return readerCount;
}