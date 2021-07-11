#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef struct{
    char Nama[30];
    int Tanggal;
    int Harga;
    int Berat;
}
info;
info dry[1000], dalam[1000];
FILE *in,file1,file2,file3;

void data();
void input();
void tampil_data();
void searching();
void sequential_nama();
void sequential_tanggal();
void binary_nama();
void binary_tanggal();
void bubble_nama(info dalam[],int banyak);
void bubble_tanggal(info dalam[],int banyak);
void sorting();
void bubble_sort(info dalam[],int banyak);
void selection_sort(info dalam[],int banyak);
void insertion_sort(info dalam[],int banyak);
void shell_sort(info dalam[],int banyak);
void sort_merge(info dalam[],int low,int high);
void s_merge(info dalam[],int low,int mid,int high);
void quick_sort(info dalam[], int first, int last);
void sort();

int pilih,banyak_data,caritgl,total;
char kembali,cekfile,cari_nama[30],namafile[30],namafile2[30],namasorting[50];
string s;

int main(){
    do{
        system("cls");
        cout<<"=================================================="<<endl;
        cout<<"=====| SELAMAT DATANG DALAM PROGRAM LAUNDRY |====="<<endl;
        cout<<"=================================================="<<endl;
        cout<<"Menu\t: "<<endl;
        cout<<"1.Data Pelanggan"<<endl;
        cout<<"2.Searching"<<endl;
        cout<<"3.Sorting"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"================================================="<<endl;
        cout<<"Masukkan menu yang anda pilih : ";cin>>pilih;
		switch(pilih)
        {
            case 1:
                system("cls");
                data();
            break;
            case 2:
                system("cls");
                searching();
            break;
            case 3:
                system("cls");
                sorting();
            break;
            case 4:
                system("cls");
                cout<<"Terima Kasih!"<<endl;
            break;
            default:
                system("cls");
                cout <<"Input Salah!"<<endl;
            break;
        }
        cout<<"\nKembali ke Menu (y/n) ? : ";cin>>kembali;
        system("cls");
    }
    while(kembali=='Y'||kembali=='y');
}

void data(){
    int pilih;
    cout<<"===================================="<<endl;
	cout<<"----------|DATA PELANGGAN|----------"<<endl;
	cout<<"===================================="<<endl;
    cout<<"MENU : "<<endl;
    cout<<"1. MENDAFTAR PELANGGAN"<<endl;
    cout<<"2. TAMPILKAN DATA PELANGGAN"<<endl;
    cout<<"3. KEMBALI KE MENU"<<endl;
    cout<<"===================================="<<endl;
    cout<<"MASUKKAN MENU YANG ANDA PILIH : ";cin>>pilih;

    switch(pilih){
		case 1:
			system("cls");
			input();
			break;
		case 2:
			system("cls");
			tampil_data();
			break;
		case 3:
			system("cls");
			main();
		break;
		default :
			cout<< "Salah Input" <<endl <<endl;
			main();
        break;
	}
}

void input(){
    do
    {
        cout<<"masukkan nama file, data akan tersimpan : "; cin >> namafile;
        in = fopen(namafile,"r");
        if(in){
            cout<<"file sudah ada, file sebelumnya akan tertimpa.";
            cout<<"\nTetap dengan nama tersebut? (y/n) : "; cin >> cekfile;
        }else{
            cekfile='y';
        }
    }
    while(cekfile=='n'||cekfile=='N');
    while(cekfile=='y'||cekfile=='Y')
    {
        in=fopen(namafile,"w");
        cout <<"\nBanyak data   : ";cin>>banyak_data;
        fwrite(&banyak_data,sizeof(banyak_data),1,in);
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<banyak_data; i++)
        {
            cout<<"\ndata ke-" << i+1 << endl;
            cout<<"Nama\t: "; cin.ignore();cin.getline(dry[i].Nama,sizeof(dry[i].Nama));
            cout<<"Tanggal\t: "; cin>>dry[i].Tanggal; 
            cout<<"Berat\t: "; cin>>dry[i].Berat; 
        }
        cout<<"\n----------------------------------";
        fwrite(&dry,sizeof(dry),1,in);
        fclose(in);
        cekfile='n';
    }
}

void tampil_data(){
    cout<<"Masukkan nama file : ";cin>>namafile;
    in=fopen(namafile,"r");
    fread(&banyak_data,sizeof(banyak_data),1,in);
    cout<<"\nJumlah Data Pada File "<<namafile<<" : "<<banyak_data<<endl;

    if(!in){
        cout<<"file tidak ditemukan!";
    }else if(banyak_data==0){
        cout<<"file kosong!";
    }else{
        cout<<"-------------------------------------------------------------------------"<<endl;
	    cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|  Total Harga\t|"<<endl;
	    cout<<"-------------------------------------------------------------------------";
        for (int i=0; i<banyak_data; i++){
            fread(&dry[i],sizeof(dry[i]),1,in); 
            cout<<endl;
            cout<<setw(3)<<i+1;
            cout<<setw(11)<<dry[i].Nama;
            cout<<setw(17)<<dry[i].Tanggal;
            cout<<setw(15)<<dry[i].Berat;
            total=dry[i].Berat*9000;
            cout<<setw(21)<<total;
        }
        cout<<"\n-------------------------------------------------------------------------"<<endl;
    }
    fclose(in);
}

void searching()
{	char ulang;
	do{
		cout<<"========================================"<<endl;
		cout<<"---------------|SEACHING|---------------"<<endl;
		cout<<"========================================"<<endl;
        cout<<"Menu : "<<endl;
        cout<<"1.Sequential Searching"<<endl;
        cout<<"2.Binary Search"<<endl;
        cout<<"3.Kembali ke Menu Utama"<<endl;
        cout<<"========================================"<<endl;
        cout<<"Pilih menu : ";cin>>pilih;
        
        if (pilih==1){
			int in;
			system("cls");
			cout<<"======================================="<<endl;
			cout<<"----------|Sequential Search|----------"<<endl;
			cout<<"======================================="<<endl;
            cout<<"Memilih Nomor : "<<endl;
			cout<<"1. Mencari Nama Pelanggan"<<endl;
			cout<<"2. Mencari Tanggal Pelanggan"<<endl;
			cout<<"3. Kembali Ke Menu Utama"<<endl;
            cout<<"======================================="<<endl;
			cout<<"Masukkan Pilihan : "; cin>>in;

			if (in==1){
                system("cls");
				sequential_nama();
			}
			else if (in==2){
                system("cls");
				sequential_tanggal();
			}
			cout<<"\nUlangi searching(y/n)?"; cin>>ulang;
			system("cls");
		}
		else if (pilih==2){
			system("cls");
			cout<<"Masukkan nama file : ";cin>>namafile;
            in=fopen(namafile,"r");
            fread(&banyak_data,sizeof(banyak_data),1,in);
			total=banyak_data;/*ngonversi banyak supaya ga ngubah data jadi jumlah sbg
			size dr arraynya utk sort*/
            if(!in){
                cout<<"File tidak ada di dalam direktori";
			}else if(banyak_data==0){
                cout<<"File kosong";
			}else{
			    int menu;
				cout<<"\n======================================="<<endl;
			    cout<<"------------|Binary Search|------------"<<endl;
			    cout<<"======================================="<<endl;
                cout<<"Memilih Nomor : "<<endl;
				cout<<"1. Mencari Nama Pelanggan"<<endl;
				cout<<"2. Mencari Tanggal Pelanggan"<<endl;
				cout<<"3. Kembali Ke Menu Utama"<<endl;
                cout<<"======================================="<<endl;
				cout<<"Masukkan pilihan : "; cin>>menu;
				
                if(menu==1){
				    system("cls");
				    fread(&dry,sizeof(dry),1,in);
				    for(int j=0;j<banyak_data;j++){
					dalam[j]=dry[j];
                    }
                    fclose(in);
				    system("cls");
				    bubble_nama(dalam,total);
				    binary_nama();
				}
                else if(menu==2){
				    system("cls");
				    fread(&dry,sizeof(dry),1,in);
				    for(int j=0;j<banyak_data;j++){
					    dalam[j]=dry[j];
                        }
                        fclose(in);
					    system("cls");
					    bubble_tanggal(dalam,total);
					    binary_tanggal();
				    }
                    else if (menu==3){
                        system("cls");
                        searching();
                    }
				cout<<"\nUlangi searching (y/n) ? : "; cin>>ulang;
			    system("cls");
			}
		}
		else if(pilih==3){
			main();
		}
	}
    while (ulang=='y'||ulang=='Y');
}

void sequential_nama(){

    system("cls");
    cout<<"masukkan nama file\t: ";cin>>namafile;
    in=fopen(namafile,"r");
    fread(&banyak_data,sizeof(banyak_data),1,in);

    if(!in){
        cout << "file tidak ditemukan";
    }else if(banyak_data==0){
        cout << "file kosong";
    }else{
        info isi[banyak_data];
        fread(&dry,sizeof(dry),1,in);
        for(int x=0; x<banyak_data; x++){
            isi[x]=dry[x];
        }
        fclose(in);

		cout<<"Masukkan nama yang anda cari\t: ";cin.ignore();cin.getline(cari_nama,sizeof(cari_nama));
        int jml = 0;
        for(int i=0;i<banyak_data;i++){
            if(strcmp(cari_nama,isi[i].Nama)==0){
                cout<<"\n-------------------------------------------------------------------------"<<endl;
	            cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|  Total Harga\t|"<<endl;
	            cout<<"-------------------------------------------------------------------------"<<endl; 
                cout<<setw(3)<<i+1;
                cout<<setw(11)<<dry[i].Nama;
                cout<<setw(17) <<dry[i].Tanggal;
                cout<<setw(15)<<dry[i].Berat; 
                total=dry[i].Berat*9000;
                cout<<setw(21)<<total;
                cout<<"\n-------------------------------------------------------------------------"<<endl;
                jml++;
            }
        }
        if(jml==0){
            cout << "data yang anda cari tidak ada"<<endl;
        }
    }
}

void sequential_tanggal()
{	
	system("cls");
	int cari;
	cout<<"\n";
	cout<<"Masukkan nama file : ";cin>>namafile;
    in=fopen(namafile,"r");
    fread(&banyak_data,sizeof(banyak_data),1,in);
    
    if(!in){
        cout<<"File tidak ada di direktori";
    }else if(banyak_data==0){
        cout<<"File kosong";
    }else{
        info isi[banyak_data];/*supaya ga ngubah data yang ada di banyak*/
        fread(&dry,sizeof(dry),1,in);
        for(int x=0; x<banyak_data;x++){
            isi[x]=dry[x];
        }
        fclose(in);
		cout<<"Masukkan tanggal yang anda dicari: "; cin>>cari;
        int jml = 0;
        for(int i=0;i<banyak_data;i++){
            if(cari==isi[i].Tanggal){
                cout<<"\n-------------------------------------------------------------------------"<<endl;
	            cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|  Total Harga\t|"<<endl;
	            cout<<"-------------------------------------------------------------------------"<<endl; 
                cout<<setw(3)<<i+1;
                cout<<setw(11)<<dry[i].Nama;
                cout<<setw(17)<<dry[i].Tanggal;
                cout<<setw(15)<<dry[i].Berat; 
                total=dry[i].Berat*9000;
                cout<<setw(21)<<total;
                cout<<"\n-------------------------------------------------------------------------"<<endl;
                jml++;
            }
        }
        if(jml==0){
            cout << "data yang anda cari tidak ada" << endl;
        }
	}
}

void binary_nama(){

    system("cls");
    string nama;
    int mid,first=banyak_data,last=0,bebas[banyak_data]={0};
    cout<<"\nMasukkan Nama yang anda cari : ";cin>>nama;
    
    while (last<=first){
        mid=(first+last)/2;
        if(dalam[mid].Nama==nama){
            bebas[mid]=1;
            break;
        }else{
            if(dalam[mid].Nama<nama){
                last=mid+1;
            }else{
                first=mid-1;
            }
        }
    }

    cout<<"\n-------------------------------------------------------------------------"<<endl;
	cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|  Total Harga\t|"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    for(int i=0;i<banyak_data;i++){
        if(bebas[i]==1){
            cout<<setw(3)<<i+1;
            cout<<setw(11)<<dry[i].Nama;
            cout<<setw(17) <<dry[i].Tanggal;
            cout<<setw(15)<<dry[i].Berat;
            total=dry[i].Berat*9000;
            cout<<setw(21)<<total;
            cout<<"\n-------------------------------------------------------------------------"<<endl;
        }
    }
    fclose(in);
}

void binary_tanggal(){

    int caritgl;
    system("cls");
    int mid, first=banyak_data,last=0,bebas[banyak_data]={0};
    cout<<"\nMasukkan Tanggal yang anda cari : ";cin>>caritgl;
    
    while(last<=first){
        mid=(first+last)/2;
        if(dalam[mid].Tanggal==caritgl){
            bebas[mid]=1;
            break;
        }else{
            if(dalam[mid].Tanggal<caritgl){
                last=mid+1;
            }else{
                first=mid-1;
            }
        }
    }

    cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|  Total Harga\t|"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    for(int i=0;i<banyak_data;i++){
        if(bebas[i]==1){
            cout<<setw(3)<<i+1;
            cout<<setw(11)<<dry[i].Nama;
            cout<<setw(17) <<dry[i].Tanggal;
            cout<<setw(15)<<dry[i].Berat; 
            total=dry[i].Berat*9000;
            cout<<setw(21)<<total;
            cout<<"\n-------------------------------------------------------------------------"<<endl;
        }
    }
    fclose(in);
}

void bubble_nama(info dalam[],int banyak)
{

	info temp;/*simpan angka dlm for*/
    for(int i=0; i<banyak_data-1; i++){
        for(int j=0; j<banyak-i-1; j++){
            if (dalam[j].Nama>dalam[j+1].Nama)/*j angka array ke 0*/
            {
                temp=dalam[j];
                dalam[j]=dalam[j+1];
                dalam[j+1]=temp;
            }
        }
    }
    for(int i=0; i<banyak; i++){
        dry[i]=dalam[i];
    }
	fwrite(&dry,sizeof(dry),1,in);
	fclose(in);
    /*baru dicout disni*/
}

void bubble_tanggal(info dalam[],int banyak)
{
	info temp;/*nyimpen angka dlm for*/
    for(int i=0; i<banyak_data-1;i++){
        for(int j=0; j<banyak_data-i-1; j++){
            if (dalam[j].Tanggal>dalam[j+1].Tanggal)/*j angka array ke 0*/
            {
                temp=dalam[j];
                dalam[j]=dalam[j+1];
                dalam[j+1]=temp;
            }
        }
    }
    for(int i=0; i<banyak; i++){
        dry[i]=dalam[i];
    }
	fwrite(&dry,sizeof(dry),1,in);
	fclose(in);
    /*baru dicout disni*/
}

void sorting()
{
    int menu,banyak;
    cout<<"Masukkan nama file\t: ";cin>>namafile;
    in=fopen(namafile,"r");
    fread(&banyak_data,sizeof(banyak_data),1,in);
    banyak=banyak_data;
    
    if(!in){
        cout<<"File tidak ditemukan!";
    }else if(banyak_data==0){
        cout<<"File kosong!";
    }else{
        char balik;
        do{
            system("cls");
            fread(&dry,sizeof(dry),1,in);
            for(int j=0;j<banyak_data;j++){
                dalam[j]=dry[j];
            }
            fclose(in);

            cout<<"Metode Sorting : ";
            cout<<"\n1. Bubble Sort";
			cout<<"\n2. Selection Sort";
			cout<<"\n3. Insert Sort";
			cout<<"\n4. Shell Sort";
			cout<<"\n5. Merge Sort";
			cout<<"\n6. Quick Sort";
			cout<<"\n7. Kembali ke menu";
			cout<<"\nPilih menu : ";cin>>menu;

            switch (menu){
                case 1 :
                    system("cls");
                    bubble_sort(dalam,banyak);
                    sort();
                    cout<<"\ncoba dengan metode sorting lain <y/n> ? : ";cin>>balik;
                break;
                case 2 :
                    system("cls");
                    selection_sort(dalam,banyak);
                    sort();
                    cout<<"\nCoba dengan metode searching lain <y/n> ? : ";cin>>balik;
                break;
                case 3 :
                    system("cls");
                    insertion_sort(dalam,banyak);
                    sort();
                    cout<<"\ncoba dengan metode sorting lain <y/n> ? : ";cin>>balik;
                break;
                case 4 :
                    system("cls");
                    shell_sort(dalam,banyak);
                    sort();
                    cout<<"\ncoba dengan metode sorting lain <y/n> ? : ";cin>>balik;
                break;
                case 5 :
                    system("cls");
                    banyak_data = banyak;
                    sort_merge(dalam,0,banyak-1);
                    sort();
                    cout<<"\ncoba dengan metode sorting lain <y/n> ? : ";cin>>balik;
                break;
				case 6 :
                    system("cls");
                    banyak_data = banyak;
                    quick_sort(dalam,0,banyak-1);
                    sort();
                    cout<<"\ncoba dengan metode sorting lain <y/n> ? : ";cin>>balik;
                break;
                case 7:
                    system("cls");
                    main();
                break;
            }
        }
        while (balik=='Y' || balik=='y');
    }
}

void bubble_sort(info dalam[],int banyak_data){

    info temp;
    cout<<"\nInput file : ";cin>>namasorting;

    for(int i=0; i<banyak_data-1; i++)
    {
        for(int j=0; i<banyak_data-1; i++)
        {
            if(dalam[j].Tanggal>dalam[j+1].Tanggal)
            {
                temp=dalam[j];
                dalam[j]=dalam[j+1];
                dalam[j+1]=temp;
            }
        }
    }

    in=fopen(namasorting,"w");
    fwrite(&banyak_data,sizeof(banyak_data),1,in);
    fwrite(&dry,sizeof(dry),1,in);
    cout<<endl;
    cout<<"---------------------------------------------------------"<<endl;
	cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
    for(int i=0; i<banyak_data; i++)
    {
        dry[i]=dalam[i];
    }
    fclose(in);
}

void selection_sort(info dalam[],int banyak_data)
{
    int j;
    info temp;
    int current;
    cout<<"Input file : ";cin>>namasorting;
    for(current=0; current<banyak_data; current++){ 
		for(j=current+1; j<banyak_data; j++){ 
			if(dalam[current].Tanggal>dalam[j].Tanggal){ 
				temp=dalam[current];
				dalam[current]=dalam[j];
				dalam[j]=temp;
			} 
		} 
	}
    cout<<endl;

    in=fopen(namafile,"w");
	fwrite(&banyak_data,sizeof(banyak_data),1,in);
	fwrite(&dry,sizeof(dry),1,in);
    cout<<"\n---------------------------------------------------------"<<endl;
	cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
    for(int i=0;i<banyak_data;i++){
        dry[i]=dalam[i];
	}
	fclose(in);
}

void insertion_sort(info dalam[],int banyak_data){

    int j;
    cout<<"file yang di cari : "<<endl;
	info temp;

    for(int i=1;i<banyak_data;i++){ 
	    temp=dalam[i]; 
	    j=i-1; 
	    while((temp.Tanggal<dalam[j].Tanggal)&(j>=0)){ 
 		    dalam[j+1]=dalam[j];
             j=j-1;
 		    dalam[j+1]=temp;
        }
    }
    cout<<endl;

    in = fopen(namafile,"w");
    fwrite(&banyak_data,sizeof(banyak_data),1,in);
 	fwrite(&dry,sizeof(dry),1,in);
    cout<<"\n---------------------------------------------------------"<<endl;
	cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
    for(int i=0; i<banyak_data; i++){
        dry[i]=dalam[i];
	}
 	fclose(in); 
}

void shell_sort(info dalam [], int banyak_data)
{
    info temp;
    for(int i=banyak_data/2;i>0;i/=2){ 
        cout<<endl;
        for(int j=i;j<banyak_data;j++){
            for(int k=j-i;k>=0;k-=i){
                if(dalam[k+i].Tanggal>=dalam[k].Tanggal){
                    break;
                }else{
                    temp=dalam[k];
                    dalam[k]=dalam[k+i];
                    dalam[k+i]=temp;
                }
            }
        }
	}

    cout<<"\nHasil Sorting : "<<endl;
    in=fopen(namafile,"w");
    fwrite(&banyak_data,sizeof(banyak_data),1,in);
    fwrite(&dry,sizeof(dry),1,in);
    cout<<"\n---------------------------------------------------------"<<endl;
	cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
    for(int x=0;x<banyak_data;x++){
        dry[x]=dalam[x];
    }
    fclose(in); 
}

void sort_merge(info dalam [], int low, int high)
{
    int mid;
    if(low<high){
        mid=(low+high)/2;
        sort_merge(dalam,low,mid);
        sort_merge(dalam,mid+1,high);
        s_merge(dalam,low,mid,high);
    }

}

void s_merge(info dalam [],int low,int mid,int high){
    int x,y,z,a;
    info temp[100];
    x=low;
    y=low;
    z=mid+1;
    while((x<=mid)&&(z<=high)){
        if(dalam[x].Tanggal<=dalam[z].Tanggal){
            temp[y]=dalam[x];
            x++;
        }else{
            temp[y]=dalam[z]; z++;
        }
        y++;
    }
    if(x>mid){
        for(a=z;a<=high;a++){
            temp[y]=dalam[a]; y++;
        }
    }else{
        for(a=x;a<=mid;a++){
            temp[y]=dalam[a]; y++;
        }
    }
    for(a=low;a<=high;a++){
        dalam[a]=temp[a];
    }

    info dry[banyak_data];
    in=fopen(namafile,"w");
    fwrite(&banyak_data,sizeof(banyak_data),1,in);
    fwrite(&dry,sizeof(dry),1,in);
    cout<<"\n---------------------------------------------------------"<<endl;
	cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
    for(int x=0;x<banyak_data;x++){
        dry[x]=dalam[x];
    }
    fclose(in);
}

void quick_sort(info dalam[],int first,int last){
    
    info temp;
    int low,high;
    info list;
    low=first;
    high=last;
    list.Tanggal=dalam[(first+last)/2].Tanggal;
    do{
	    while(dalam[low].Tanggal<list.Tanggal){ 
		    low++;
	    }
	    while(dalam[high].Tanggal>list.Tanggal){
		    high--; 
	    } 
	    if(low<=high){  
		    temp = dalam[low]; 
		    dalam[low++]=dalam[high]; 
		    dalam[high--]=temp; 
        }
    }

    while(low<=high);
    if(first<high) quick_sort(dalam, first, high);
    if(low<last) quick_sort(dalam, low, last);

    info dry[banyak_data];
    in=fopen(namafile,"w");
    fwrite(&banyak_data,sizeof(banyak_data),1,in);
    fwrite(&dry,sizeof(dry),1,in);
    cout<<"\n---------------------------------------------------------"<<endl;
	cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
    for(int x=0;x<banyak_data;x++){
        dry[x]=dalam[x]; 
	}
    fclose(in);
}

void sort(){

    in=fopen(namasorting,"r");
    fread(&banyak_data,sizeof(banyak_data),1,in);
    fread(&dry,sizeof(dry),1,in);
    for(int x=0;x<banyak_data;x++)
    {
        dalam[x]=dry[x];
        cout<<setw(3)<<x+1<<setw(10)<<dalam[x].Nama<<setw(18)<<dalam[x].Tanggal<<setw(17)<<dalam[x].Berat<<endl;
        cout<<"---------------------------------------------------------"<<endl;
    }

    int dattengh,atas=banyak_data,bawah=0,bebas[banyak_data]={0};
    cout<<"\nMasukkan Tanggal yang anda cari : ";cin>>caritgl;
    while (bawah<=atas){
        dattengh=(atas+bawah)/2;
        if(dalam[dattengh].Tanggal==caritgl){
            bebas[dattengh]=1;
            break;
        }else{
            if(dalam[dattengh].Tanggal<caritgl){
                bawah=dattengh+1;
            }else{
                atas+dattengh-1;
            }
        }
    }for(int i=0;i<banyak_data;i++){
        if(bebas[i]==1){
            cout<<"\n-------------------------------------------------------------------------"<<endl;
	        cout<<"| No |\tNama Pelanggan\t|  Tanggal\t|  Berat\t|  Total Harga\t|"<<endl;
	        cout<<"-------------------------------------------------------------------------"<<endl; 
            cout<<setw(3)<<i+1;
            cout<<setw(11)<<dry[i].Nama;
            cout<<setw(17)<<dry[i].Tanggal;
            cout<<setw(15)<<dry[i].Berat; 
            total=dry[i].Berat*9000;
            cout<<setw(21)<<total;
            cout<<"\n-------------------------------------------------------------------------"<<endl;
        }
    }
    fclose(in);
}
