#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
int main(int argc,const char* argv[])
{
	int map[8][8]={
		{0,0,4,4,4,4,0,0},
		{0,0,4,2,2,4,0,0},
		{0,4,4,0,2,4,4,0},
		{0,4,0,0,6,2,4,0},
		{4,4,0,6,0,0,4,4},
		{4,0,0,4,6,6,0,4},
		{4,0,0,1,0,0,0,4},
		{4,4,4,4,4,4,4,4}
	};// 初始化地图
	int win=0,step=0,man_x=6,man_y=3;
	for(;;)
	{
		system("clear");
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				switch(map[i][j])
				{
					case 0:printf("  ");break;
					case 1:printf("R ");break;
					case 2:printf("o ");break;
					case 3:printf("R ");break;
					case 4:printf("# ");break;
					case 6:printf("□ ");break;
					case 8:printf("■ ");break;
				}
			}
			printf("\n");
		}                                         
		if(map[1][3] == 8 && map[1][4] == 8 && map[2][4] == 8 && map[3][5] == 8) //游戏获胜条件
		{
			printf("游戏胜利！共用%d步\n",step);
			return 0;
		}
		switch(getch())
		{
			case 183:if(map[man_x-1][man_y] == 0 || map[man_x-1][man_y] == 2)  //前方是路可走
			{
				map[man_x-1][man_y]+=1;
				map[man_x][man_y]-=1;
				man_x=man_x-1;
				step++;break;
			}
			if(map[man_x-1][man_y] == 6 || map[man_x-1][man_y] == 8)   //前方是箱子判断可不可推
			{
				if(map[man_x-2][man_y] == 2 || map[man_x-2][man_y] == 0)
				{
					map[man_x-2][man_y]+=6;
					map[man_x-1][man_y]-=6;
					map[man_x-1][man_y]+=1;
					map[man_x][man_y]-=1;
			     	man_x=man_x-1;
					step++;
				}
			};break;
			case 184:if(map[man_x+1][man_y] == 0 || map[man_x+1][man_y] == 2)
			{
				map[man_x+1][man_y]+=1;
				map[man_x][man_y]-=1;
				man_x=man_x+1;
				step++;break;
			}
			if(map[man_x+1][man_y] == 6 || map[man_x+1][man_y] == 8)
			{
				if(map[man_x+2][man_y] == 2 || map[man_x+2][man_y] == 0)
				{
					map[man_x+2][man_y]+=6;
					map[man_x+1][man_y]-=6;
					map[man_x+1][man_y]+=1;
					map[man_x][man_y]-=1;
		     		man_x=man_x+1;
					step++;
				}
			};break;
			case 185:if(map[man_x][man_y+1] == 0 || map[man_x][man_y+1] == 2)
			{
				map[man_x][man_y+1]+=1;
				map[man_x][man_y]-=1;
				man_y=man_y+1;
				step++;break;
			}
			if(map[man_x][man_y+1] == 6 || map[man_x][man_y+1] == 8)
			{
				if(map[man_x][man_y+2] == 2 || map[man_x][man_y+2] == 0)
				{
					map[man_x][man_y+2]+=6;
					map[man_x][man_y+1]-=6;
					map[man_x][man_y+1]+=1;
					map[man_x][man_y]-=1;
					man_y=man_y+1;
					step++;
				}
			};break;
			case 186:if(map[man_x][man_y-1] == 0 || map[man_x][man_y-1] == 2)
			{
				map[man_x][man_y-1]+=1;
				map[man_x][man_y]-=1;
				man_y=man_y-1;
				step++;break;
			}
			if(map[man_x][man_y-1] == 6 || map[man_x][man_y-1] == 8)
			{
				if(map[man_x][man_y-2] == 2 || map[man_x][man_y-2] == 0)
				{
					map[man_x][man_y-2]+=6;
					map[man_x][man_y-1]-=6;
					map[man_x][man_y-1]+=1;
					map[man_x][man_y]-=1;
					man_y=man_y-1;
					step++;
				}
			};break;
        }
	}

}
/*推箱子switch语句重复的优化
      int ox=0,oy=0;
	  switch(getch())
	  {
		  case 183:ox--;break;
		  case 184:ox++;break;
		  case 185:oy--;break;
		  case 186:oy++;break;
	  }
	  if()   //前方是路、坐标加偏移值  0==map[man_x+0x][man_y+oy]
	  {
		  map[man_x+ox][man_y+oy]+=1;
		  map[man_x][man_y]-=1;
		  man_x+=ox;man_y+=oy;step++    //加continue 或下方else if
	  }
	  if() // 前方的前方 man_x+ox*2
	  {
		  map[man_x+ox*2][man_y+oy*2];

	  }
		  
















*/
