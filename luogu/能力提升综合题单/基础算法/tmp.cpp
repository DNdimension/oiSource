#include <iostream>
using namespace std;

const int LEFTBOUND=0,RIGHTBOUND=31,UPBOUND=7,DOWNBOUND=0,DNT=144,DEADZONE=36,WINNUM=7;
int dnt=0,OVERpix[71],WINpix[45];
int ptoi(int px,int py) { //px-[0,31],py-[0,7]
  py=max(min(UPBOUND,py),DOWNBOUND)<<3; //py*=3
  if(px<8) return 192+py+max(px,LEFTBOUND); // 8*8*3+py+max(px,LEFTBOUND)
  if(px<16) return 120+py+px; // 8*8*2+py+(px-8)
  if(px<24) return 48+py+px; // 8*8+py+(px-16)
  return py+(min(px,RIGHTBOUND)-24); // py+(min(px,RIGHTBOUND)-24)
}

inline void initWin() {
  dnt=0;
  WINpix[dnt++]=ptoi(1, 6);
  for(int i=2;i<7;i++) {
  WINpix[dnt++]=ptoi(2, i);
  WINpix[dnt++]=ptoi(6, i);
  }
  WINpix[dnt++]=ptoi(3, 1);
  WINpix[dnt++]=ptoi(3, 2);
  WINpix[dnt++]=ptoi(5, 1);
  WINpix[dnt++]=ptoi(5, 2);
  WINpix[dnt++]=ptoi(4, 3);
  WINpix[dnt++]=ptoi(4, 4);
  WINpix[dnt++]=ptoi(4, 5);
  
  for(int i=1;i<7;i++) WINpix[dnt++]=ptoi(12, i);
  WINpix[dnt++]=ptoi(11, 1);
  WINpix[dnt++]=ptoi(11, 6);
  WINpix[dnt++]=ptoi(13, 1);
  WINpix[dnt++]=ptoi(13, 6);

  for(int i=1;i<7;i++) {
    WINpix[dnt++]=ptoi(17, i);
    WINpix[dnt++]=ptoi(22, i);
  }
  WINpix[dnt++]=ptoi(18, 5);
  WINpix[dnt++]=ptoi(19, 4);
  WINpix[dnt++]=ptoi(19, 3);
  WINpix[dnt++]=ptoi(20, 2);
  WINpix[dnt++]=ptoi(21, 1);
  

  return;
}
int main() {
	initWin();
	for(int i=0;i<45;i++) cout<<WINpix[i]<<',';
	return 0;
}