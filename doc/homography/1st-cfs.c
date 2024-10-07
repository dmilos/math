// Last time stamp was: 1999-08-29/01:04
// First close form solution of homography

#include   <conio.h>
#include   <stdio.h>
#include  "displayh.h"
#include   "vectorh.h"
#include   "matrixh.h"

void perspect( VECTOR3 *to, VECTOR3 t, MATRIX3 m  )/* to=m(t) */
 {
  double dp;

  dp=t.x*m.a31+t.y*m.a32+m.a33;

  to->x=(t.x*m.a11+t.y*m.a12+m.a13)/dp;
  to->y=(t.x*m.a21+t.y*m.a22+m.a23)/dp;
 }
int make_2d_perspect( VECTOR3 xt, VECTOR3 x1, VECTOR3 x2, VECTOR3 x3, MATRIX3 *mat)
 {
  double det;

  det=  x1.y*x2.x - x1.x*x2.y
       - x1.y*x3.x + x2.y*x3.x
       + x1.x*x3.y - x2.x*x3.y ;
  if( is_epsilon( det ) ) return 0;

  VECTOR3__sub( x1, xt ); VECTOR3__sub( x2, xt ); VECTOR3__sub( x3, xt );

  mat->a11=x1.x * (   x2.y * x3.x  -  x2.x * x3.y )/det;
  mat->a12=x2.x * (   x1.x * x3.y  -  x1.y * x3.x )/det;
  mat->a13=xt.x;
  mat->a21=x1.y * (   x2.y * x3.x  -  x2.x * x3.y )/det;
  mat->a22=x2.y * (   x1.x * x3.y  -  x1.y * x3.x )/det;
  mat->a23=xt.y;
  mat->a31= ( - x1.y * x2.x  +  x1.x * x2.y
              + x1.y * x3.x  -  x1.x * x3.y)/det;

  mat->a32= ( - x1.y * x2.x  +  x1.x * x2.y
              - x2.y * x3.x  +  x2.x * x3.y)/det;

  mat->a33=1.0;
  if(fabs( MATRIX3__det( *mat ) )<0.001)return 0;
  return 1;

 }

void main(void)
 {
  int i,koja=1;
  double alfa,xr,yr;
  VECTOR3 ti,to,kt[4],or[4];

  MATRIX3 mat;

  printf("Strelicama se pomera tacka \n");
  printf("Razmaknicom se menja tacka  \n");
  printf("Ako se pojavi krug u gornjem levom uglu preslikavanje ne postoji \n");
  printf("Press space to continue... \n");

  getch();

  DISPLAY__open();

  v_load(kt[0],0.0,0.0,0.0);
  v_load(kt[1],1.0,0.0,0.0);
  v_load(kt[2],0.0,1.0,0.0);
  v_load(kt[3],1.0,1.0,0.0);
  or[0]=kt[0];  or[1]=kt[1];  or[2]=kt[2];  or[3]=kt[3];
  /*
  mat.a11=mat.a22=mat.a33=1.0;
  mat.a12=mat.a13=mat.a21=mat.a23=mat.a31=mat.a32=0.0;
  */
  ponovo:
  DISPLAY__clear()
  DISPLAY__setcolor( 0x00f000 );
  v_load(to,0.0,0.0,0.0);
  krug(gfx2+to.x*gfx4,gfy2-to.y*gfy4,3);
  line(gfx2+to.x*gfx4,gfy2-to.y*gfy4,gfx2+kt[0].x*gfx4,gfy2-kt[0].y*gfy4);
  v_load(to,1.0,0.0,0.0);
  line(gfx2+to.x*gfx4,gfy2-to.y*gfy4,gfx2+kt[1].x*gfx4,gfy2-kt[1].y*gfy4);
  v_load(to,0.0,1.0,0.0);
  line(gfx2+to.x*gfx4,gfy2-to.y*gfy4,gfx2+kt[2].x*gfx4,gfy2-kt[2].y*gfy4);
  v_load(to,1.0,1.0,0.0);
  line(gfx2+to.x*gfx4,gfy2-to.y*gfy4,gfx2+kt[3].x*gfx4,gfy2-kt[3].y*gfy4);
  setcolor(LIGHTBLUE);
  for(i=0;i<4; i++)
   krug(gfx2+kt[i].x*gfx4,gfy2-kt[i].y*gfy4,i*2);

  setcolor(LIGHTRED);
  krug(gfx2+kt[koja].x*gfx4,gfy2-kt[koja].y*gfy4,10);

  if(make_2d_perspect(kt[0],kt[1],kt[2],kt[3],&mat)==0)
   { krug(100,100,100);goto n_comand; }

  setcolor(YELLOW);
  for(i=0;i<4; i++)
   {
    perspect(or[i],mat,&to);
    krug(gfx2+to.x*gfx4,gfy2-to.y*gfy4,i*3);
   }

  v_load(ti,sin(0.0),cos(0.0),0.0);
  perspect(ti,mat,&to);
  moveto(gfx2+to.x*gfx4,gfy2-to.y*gfy4);
  setcolor(15);
  for(alfa=0.1;alfa<6.3;alfa+=0.1)
   {
    v_load(ti,sin(alfa),cos(alfa),0.0);
    perspect(ti,mat,&to);
    lineto(gfx2+to.x*gfx4,gfy2-to.y*gfy4);
   }

  v_load(ti,sin(0.0),cos(0.0),0.0);
  moveto(gfx2+ti.x*gfx4,gfy2-ti.y*gfy4);
  for(alfa=0.1;alfa<6.3;alfa+=0.1)
   {
    v_load(to,sin(alfa),cos(alfa),0.0);
    lineto(gfx2+to.x*gfx4,gfy2-to.y*gfy4);
   }

 setcolor(MAGENTA);
 for(yr=0.0;yr<1.0; yr+=0.1)
  {
   ti.x=0.0 ; ti.y=yr; ti.z=0.0;
   perspect(ti,mat,&to);
   moveto( gfx2+to.x*gfx4,gfy2-to.y*gfy4);

   for(xr=0.0 ; xr<1.0; xr+=0.1)
    {
     ti.x=xr;
     perspect(ti,mat,&to);
     lineto( gfx2+to.x*gfx4, gfy2-to.y*gfy4);

    }
  }


 for(xr=0.0;xr<1.0;xr+=0.1)
  {
   ti.x=xr; ti.y=0.0; ti.z=0.0;
   perspect(ti,mat,&to);
   moveto(gfx2+to.x*gfx4,gfy2-to.y*gfy4);
   for(yr=0.0 ;yr<1.0;yr+=0.1)
    {
     ti.y=yr;
     perspect(ti,mat,&to);
     lineto(gfx2+to.x*gfx4,gfy2-to.y*gfy4);

    }
  }

 /*
 setcolor(15);
 switch(koja)
  {
   case(0):outtextxy(0,0,"t");break;
   case(1):outtextxy(0,0,"1");break;
   case(2):outtextxy(0,0,"2");break;
   case(3):outtextxy(0,0,"3");break;
  }
 */
  n_comand:

  switch(getch())
   {
    case( 0 ):
     switch( getch() )
     {
      case(75):kt[koja].x-=0.05;goto ponovo;
      case(77):kt[koja].x+=0.05;goto ponovo;
      case(72):kt[koja].y+=0.05;goto ponovo;
      case(80):kt[koja].y-=0.05;goto ponovo;
     } break;

    case(' '):koja++;koja%=3;koja++;goto ponovo;

   }

  DISPLAY__close();
 }
