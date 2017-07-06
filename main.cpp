#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

DWORD ekranGenisligi = GetSystemMetrics(SM_CXSCREEN);
DWORD ekranYuksekligi = GetSystemMetrics(SM_CYSCREEN);

unsigned int mx;
unsigned int my;
POINT isaret;

/**RENKLERI HAZIRLAR*/
void renkleriHazirla(){
    int renkSayisi , i;
    renkSayisi=getmaxcolor();
    for(i=0 ; i<=renkSayisi ; i++){
        setfillstyle(SOLID_FILL,i);
        bar(ekranGenisligi-130 ,10+(40*i) , ekranGenisligi-80 , 40+(40*i));
    }
}

/**DUGMELERI HAZIRLAR*/
void dugmeleriHazirla(){
    int i;
    for(i=0 ; i<5 ; i++){
        setfillstyle(SOLID_FILL,15);
        bar(10+(110*i), ekranYuksekligi-80, 110+(110*i), ekranYuksekligi-50);
    }
    setbkcolor(15);
    setcolor(0);
    outtextxy(35+(110*0), ekranYuksekligi-74 , "Kalem");
    outtextxy(15+(110*1), ekranYuksekligi-74 , "Dikdortgen");
    outtextxy(35+(110*2), ekranYuksekligi-74 , "Daire");
    outtextxy(35+(110*3), ekranYuksekligi-74 , "Ucgen");
    outtextxy(35+(110*4), ekranYuksekligi-74 , "Cizgi");

    bar(ekranGenisligi-470 , ekranYuksekligi-80 ,ekranGenisligi-370 ,ekranYuksekligi-50);
    outtextxy(ekranGenisligi-450 , ekranYuksekligi-74 , "Temizle");
    bar(ekranGenisligi-360, ekranYuksekligi-80, ekranGenisligi-260, ekranYuksekligi-50);
    outtextxy(ekranGenisligi-335, ekranYuksekligi-74 , "Kaydet");
    bar(ekranGenisligi-250, ekranYuksekligi-80, ekranGenisligi-150, ekranYuksekligi-50);
    outtextxy(ekranGenisligi-220, ekranYuksekligi-74 , "Cikis");
}

/**GRAFIK EKRANINI HAZIRLAR*/
void ekraniHazirla(int secim){
    initwindow(ekranGenisligi, ekranYuksekligi, "" , -3,-3 );
    setbkcolor(COLOR(199,208,209));
    cleardevice();
    bar(0,0,ekranGenisligi-150,ekranYuksekligi-100);

    if(secim==2){
        readimagefile("resim.bmp" , 0 , 0 , ekranGenisligi-150 , ekranYuksekligi-100);
    }

    renkleriHazirla();
    dugmeleriHazirla();
}

void kaydet(){
    writeimagefile("resim.bmp" , 0 ,0 ,ekranGenisligi-150,ekranYuksekligi-100);
    delay(100);
}

void dikdortgen();
void ucgen();
void daire();
void cizgi();

/**KALEM*/
void kalem(){
    int kontrol=1;
    int i=0, gecmisx, gecmisy;
    while(1){
        GetCursorPos(&isaret);
        mx=isaret.x;
        my=isaret.y;
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(mx<ekranGenisligi-150&&my<ekranYuksekligi-100){
                while(kontrol==1){
                    gecmisx=mx;
                    gecmisy=my;
                    kontrol=0;
                }
                line(gecmisx,gecmisy,mx,my);
                gecmisx=mx;
                gecmisy=my;
                delay(1);
            }
            if(ismouseclick(WM_LBUTTONUP)){
                kontrol=1;
            }
            clearmouseclick(WM_LBUTTONUP);
            if(mx>ekranGenisligi-130&&mx<ekranGenisligi-80){
                for(i=0;i<16;i++){
                    if(my<40+(40*i)&&my>10+(40*i)){
                        setcolor(i);
                    }
                }
            }
            if(my>ekranYuksekligi-80 && my<ekranYuksekligi-50){
                /**DIKDORTGEN*/
                if(mx>10+(110*1)&&mx<110+(110*1)){
                    dikdortgen();
                }
                /**DAIRE*/
                if(mx>10+(110*2)&&mx<110+(110*2)){
                    daire();
                }
                /**UCGEN*/
                if(mx>10+(110*3)&&mx<110+(110*3)){
                    ucgen();
                }
                /**CIZGI*/
                if(mx>10+(110*4)&&mx<110+(110*4)){
                    cizgi();
                }
                /**TEMIZLE*/
                if(mx>ekranGenisligi-470&&mx<ekranGenisligi-370){
                        setfillstyle(SOLID_FILL,15);
                        bar(0,0,ekranGenisligi-150,ekranYuksekligi-100);
                        setfillstyle(SOLID_FILL,0);
                        kalem();
                }
                /**KAYDET*/
                if(mx>ekranGenisligi-360&&mx<ekranGenisligi-260){
                        kaydet();
                        kalem();
                }
                /**CIK*/
                if(mx>ekranGenisligi-250&&mx<ekranGenisligi-150){
                        exit(1);
                }
            }
        }
    }
}

/**DIKDORTGEN*/
void dikdortgen(){
    int i;
    while(1){
        GetCursorPos(&isaret);
        mx=isaret.x;
        my=isaret.y;
        unsigned int ax , ay;
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(mx<ekranGenisligi-150&&my<ekranYuksekligi-100){
                clearmouseclick(WM_LBUTTONUP);
                ax=mx;
                ay=my;
                while(!ismouseclick(WM_LBUTTONUP)){
                    GetCursorPos(&isaret);
                    mx=isaret.x;
                    my=isaret.y;
                }
                clearmouseclick(WM_LBUTTONUP);
                if(mx<=ekranGenisligi-150&&my<=ekranYuksekligi-100){
                    int nokta[10]={ax,ay,mx,ay,mx,my,ax,my,ax,ay};
                    drawpoly(5,nokta);
                }

            }
            if(mx>ekranGenisligi-130&&mx<ekranGenisligi-80){
                for(i=0;i<16;i++){
                    setcolor(i);
                }
            }
            if(my>ekranYuksekligi-80 && my<ekranYuksekligi-50){
                /**KALEM*/
                if(mx>10+(110*0)&&mx<110+(110*0)){
                    kalem();
                }
                /**DAIRE*/
                if(mx>10+(110*2)&&mx<110+(110*2)){
                    daire();
                }
                /**UCGEN*/
                if(mx>10+(110*3)&&mx<110+(110*3)){
                    ucgen();
                }
                /**CIZGI*/
                if(mx>10+(110*4)&&mx<110+(110*4)){
                    cizgi();
                }
                /**TEMIZLE*/
                if(mx>ekranGenisligi-470&&mx<ekranGenisligi-370){
                        setfillstyle(SOLID_FILL,15);
                        bar(0,0,ekranGenisligi-150,ekranYuksekligi-100);
                        setfillstyle(SOLID_FILL,0);
                        kalem();
                }
                /**KAYDET*/
                if(mx>ekranGenisligi-360&&mx<ekranGenisligi-260){
                        kaydet();
                        kalem();
                }
                /**CIK*/
                if(mx>ekranGenisligi-250&&mx<ekranGenisligi-150){
                        exit(1);
                }
            }
        }
    }
}

/**DAIRE*/
void daire(){
    int i;
    unsigned int ax , ay;
    double r , karesi;
    while(1){
        GetCursorPos(&isaret);
        mx=isaret.x;
        my=isaret.y;
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(mx<ekranGenisligi-150&&my<ekranYuksekligi-100){
                clearmouseclick(WM_LBUTTONUP);
                ax=mx;
                ay=my;
                while(!ismouseclick(WM_LBUTTONUP)){
                    GetCursorPos(&isaret);
                    mx=isaret.x;
                    my=isaret.y;

                }
                karesi=((ax-mx)*(ax-mx))+((ay-my)*(ay-my));
                r=sqrt(karesi);
                clearmouseclick(WM_LBUTTONUP);
                if(ax+r<=ekranGenisligi-150&&ay+r<=ekranYuksekligi-100){
                    circle(ax,ay,r);
                }


            }

            if(mx>ekranGenisligi-130&&mx<ekranGenisligi-80){
                for(i=0;i<16;i++){
                    if(my<40+(40*i)&&my>10+(40*i)){
                        setcolor(i);
                    }
                }
            }
            if(my>ekranYuksekligi-80 && my<ekranYuksekligi-50){
                /**KALEM*/
                if(mx>10+(110*0)&&mx<110+(110*0)){
                    kalem();
                }
                /**DIKDORTGEN*/
                if(mx>10+(110*1)&&mx<110+(110*1)){
                    dikdortgen();
                }
                /**UCGEN*/
                if(mx>10+(110*3)&&mx<110+(110*3)){
                    ucgen();
                }
                /**CIZGI*/
                if(mx>10+(110*4)&&mx<110+(110*4)){
                    cizgi();
                }
                /**TEMIZLE*/
                if(mx>ekranGenisligi-470&&mx<ekranGenisligi-370){
                        setfillstyle(SOLID_FILL,15);
                        bar(0,0,ekranGenisligi-150,ekranYuksekligi-100);
                        setfillstyle(SOLID_FILL,0);
                        kalem();
                }
                /**KAYDET*/
                if(mx>ekranGenisligi-360&&mx<ekranGenisligi-260){
                        kaydet();
                        kalem();
                }
                /**CIK*/
                if(mx>ekranGenisligi-250&&mx<ekranGenisligi-150){
                        exit(1);
                }
            }
        }
    }
}

/**UCGEN*/
void ucgen(){
    int i;
    unsigned int ax,ay;
    while(1){
        GetCursorPos(&isaret);
        mx=isaret.x;
        my=isaret.y;
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(mx<ekranGenisligi-150&&my<ekranYuksekligi-100){
                clearmouseclick(WM_LBUTTONUP);
                ax=mx;
                ay=my;
                while(!ismouseclick(WM_LBUTTONUP)){
                    GetCursorPos(&isaret);
                    mx=isaret.x;
                    my=isaret.y;
                }
                clearmouseclick(WM_LBUTTONUP);
                if(mx<=ekranGenisligi-150&&my<=ekranYuksekligi-100){
                    int noktalar[8]={ax,ay,mx,ay,((ax+mx)/2),my,ax,ay};
                    drawpoly(4,noktalar);
                }

            }
            if(mx>ekranGenisligi-130&&mx<ekranGenisligi-80){
                for(i=0;i<16;i++){
                    if(my<40+(40*i)&&my>10+(40*i)){
                        setcolor(i);
                    }
                }
            }
            if(my>ekranYuksekligi-80 && my<ekranYuksekligi-50){
                /**KALEM*/
                if(mx>10+(110*0)&&mx<110+(110*0)){
                    kalem();
                }
                /**DIKDORTGEN*/
                if(mx>10+(110*1)&&mx<110+(110*1)){
                    dikdortgen();
                }
                /**DAIRE*/
                if(mx>10+(110*2)&&mx<110+(110*2)){
                    daire();
                }
                /**CIZGI*/
                if(mx>10+(110*4)&&mx<110+(110*4)){
                    cizgi();
                }
                /**TEMIZLE*/
                if(mx>ekranGenisligi-470&&mx<ekranGenisligi-370){
                        setfillstyle(SOLID_FILL,15);
                        bar(0,0,ekranGenisligi-150,ekranYuksekligi-100);
                        setfillstyle(SOLID_FILL,0);
                        kalem();
                }
                /**KAYDET*/
                if(mx>ekranGenisligi-360&&mx<ekranGenisligi-260){
                        kaydet();
                        kalem();
                }
                /**CIK*/
                if(mx>ekranGenisligi-250&&mx<ekranGenisligi-150){
                        exit(1);
                }
            }
        }
    }
}

/**CIZGI*/
void cizgi(){
    int i;
    while(1){
        GetCursorPos(&isaret);
        mx=isaret.x;
        my=isaret.y;
        unsigned int ax , ay;
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(mx<ekranGenisligi-150&&my<ekranYuksekligi-100){
                clearmouseclick(WM_LBUTTONUP);
                ax=mx;
                ay=my;
                while(!ismouseclick(WM_LBUTTONUP)){
                    GetCursorPos(&isaret);
                    mx=isaret.x;
                    my=isaret.y;
                }
                clearmouseclick(WM_LBUTTONUP);
                if(mx<=ekranGenisligi-150&&my<=ekranYuksekligi-100){
                    line(ax,ay,mx,my);
                }
            }
            if(mx>ekranGenisligi-130&&mx<ekranGenisligi-80){
                for(i=0;i<16;i++){
                    if(my<40+(40*i)&&my>10+(40*i)){
                        setcolor(i);
                    }
                }
            }
            if(my>ekranYuksekligi-80 && my<ekranYuksekligi-50){
                /**KALEM*/
                if(mx>10+(110*0)&&mx<110+(110*0)){
                    kalem();
                }
                /**DIKDORTGEN*/
                if(mx>10+(110*1)&&mx<110+(110*1)){
                    dikdortgen();
                }
                /**DAIRE*/
                if(mx>10+(110*2)&&mx<110+(110*2)){
                    daire();
                }
                /**UCGEN*/
                if(mx>10+(110*3)&&mx<110+(110*3)){
                    ucgen();
                }
                /**TEMIZLE*/
                if(mx>ekranGenisligi-470&&mx<ekranGenisligi-370){
                        setfillstyle(SOLID_FILL,15);
                        bar(0,0,ekranGenisligi-150,ekranYuksekligi-100);
                        setfillstyle(SOLID_FILL,0);
                        kalem();
                }
                /**KAYDET*/
                if(mx>ekranGenisligi-360&&mx<ekranGenisligi-260){
                        kaydet();
                        kalem();
                }
                /**CIK*/
                if(mx>ekranGenisligi-250&&mx<ekranGenisligi-150){
                        exit(1);
                }
            }
        }
    }
}

int main(){
    int secim;
    sec:
    printf("1.Yeni Resim\n");
    printf("2.Kayitli Resim\n");
    scanf("%d",&secim);
    if(secim<1||secim>2){
        printf("Yanlis Secim Yaptiniz. Birdaha Secin..!\n");
        goto sec;
    }

    ekraniHazirla(secim);
    setfillstyle(SOLID_FILL,0);
    setcolor(0);
    kalem();

    getch();
    closegraph();
    return 0;
}
