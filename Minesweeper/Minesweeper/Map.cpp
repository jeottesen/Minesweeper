//#include <vector>
#include <cstdlib>
#include <time.h>
#include "Map.h"



bool BoxCheck(int x, int y, int check)
{
	bool bArr[8];
	// bottom
		if(++x > (iCol - 1))
		{
			--x;
		}
		else
		{
			if(vMap[x][y] == check) 
			{
				--x;
				bArr[0] = true;
			}
			else
			{
				--x;
				bArr[0] = false;
			}
		}

		// top
		if(--x < 0)
		{
			++x;
		}
		else
		{
			if(vMap[x][y] == check) 
			{
				++x;
				bArr[1] = true;
			}
			else
			{
				++x;
				bArr[1] = false;
			}
		}

		// left
		if(--y < 0)
		{
			++y;
		}
		else
		{
			if(vMap[x][y] == check) 
			{
				y++;
				bArr[2] = true;
			}
			else
			{
				y++;
				bArr[2] = false;
			}
		}

		// right
		if(++y > (iRow - 1))
		{
			--y;
		}
		else
		{
			--y;
			if(vMap[x][++y] == check) 
			{
				bArr[3] = true;
				--y;
			}
			else
			{
				bArr[3] = true;
				--y;
			}
		}


		// Top left Corner
		if(--x < 0)
		{
			++x;
		}
		else
		{
			++x;
			if(--y < 0)
			{
				++y;
			}
			else
			{
				++y;
				if(vMap[--x][--y] == check) 
				{
					++x;
					++y;
					bArr[4] = true;
				}
				else
				{
					++x;
					++y;
					bArr[4] = false;
				}
			}
		}

		// Top right corner
		if(--x < 0)
		{
			++x;
		}
		else
		{
			++x;
			if(++y > (iRow - 1))
			{
				--y;
			}
			else
			{
				--y;
				if(vMap[--x][++y] == check) 
				{
					++x;
					--y;
					bArr[5] = true;
				}
				else
				{
					++x;
					--y;
					bArr[5] = false;
				}
			}
		}

		// Bottom right corner
		if(++x > (iCol - 1))
		{
			--x;
		}
		else
		{
			--x;
			if(++y > (iRow- 1))
			{
				--y;
			}
			else
			{
				--y;
				if(vMap[++x][++y] == check) 
				{
					--x;
					--y;
					bArr[6] = true;
				}
				else
				{
					--x;
					--y;
					bArr[6] = false;
				}
			}
		}

		// Bottom Left corner
		if(++x > (iRow - 1))
		{
			--x;
		}
		else
		{
			--x;
			if(--y < 0)
			{
				++y;
			}
			else
			{
				++y;
				if(vMap[++x][--y] == check) 
				{
					--x;
					++y;
					bArr[7] = true;
				}
				else
				{
					--x;
					++y;
					bArr[7] = false;
				}
			}
		}
	
	bool bEnd = false;
	int i = 0;
	while(bEnd == true)
	{
		if(bArr[i] == true)
		{
			bEnd = true;
		}
		else
		{
			bEnd = false;
		}
		i++;
	}
	if(bEnd = true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void FBoxCheck(int x, int y, int check)
{	
	// bottom
	if(vMap[x][y] != check)
	{
		if(++x > (iCol - 1))
		{
			--x;
		}
		else
		{
			if(vMap[x][y] == check) 
			{
				vMap[--x][y]++;
			}
			else
			{
				--x;
			}
		}

		// top
		if(--x < 0)
		{
			++x;
		}
		else
		{
			if(vMap[x][y] == check) 
			{
				vMap[++x][y]++;
			}
			else
			{
				++x;
			}
		}

		// left
		if(--y < 0)
		{
			++y;
		}
		else
		{
			if(vMap[x][y] == check) 
			{
				vMap[x][++y]++;
			}
			else
			{
				++y;
			}
		}

		// right
		if(++y > (iRow - 1))
		{
			--y;
		}
		else
		{
			--y;
			if(vMap[x][++y] == check) 
			{
				vMap[x][--y]++;
			}
			else
			{
				--y;
			}
		}


		// Top left Corner
		if(--x < 0)
		{
			++x;
		}
		else
		{
			++x;
			if(--y < 0)
			{
				++y;
			}
			else
			{
				++y;
				if(vMap[--x][--y] == check) 
				{
					vMap[++x][++y]++;
				}
				else
				{
					++x;
					++y;
				}
			}
		}

		// Top right corner
		if(--x < 0)
		{
			++x;
		}
		else
		{
			++x;
			if(++y > (iRow - 1))
			{
				--y;
			}
			else
			{
				--y;
				if(vMap[--x][++y] == check) 
				{
					vMap[++x][--y]++;
				}
				else
				{
					++x;
					--y;
				}
			}
		}

		// Bottom right corner
		if(++x > (iCol - 1))
		{
			--x;
		}
		else
		{
			--x;
			if(++y > (iRow - 1))
			{
				--y;
			}
			else
			{
				--y;
				if(vMap[++x][++y] == check) 
				{
					vMap[--x][--y]++;
				}
				else
				{
					--x;
					--y;
				}
			}
		}

		// Bottom Left corner
		if(++x > (iCol - 1))
		{
			--x;
		}
		else
		{
			--x;
			if(--y < 0)
			{
				++y;
			}
			else
			{
				++y;
				if(vMap[++x][--y] == check) 
				{
					vMap[--x][++y]++;
				}
				else
				{
					--x;
					++y;
				}
			}
		}

	}
}

void FirstClick(int EmptyX, int EmptyY)
{
	MineMax = 16;
	srand((unsigned) time(NULL));
	int x = 0, y = 0;
	bool bEnd = false;
	vMap.resize(iCol, std::vector<int>(iRow));
	for(int iMine = 0; iMine < MineMax; iMine++)
	{
		do
		{
			bEnd = false;
			x = rand() % iCol;
			y = rand() % iRow;
			try
			{
				if(x > iCol || y > iRow || EmptyX == x || EmptyY == y || !(BoxCheck(EmptyX, EmptyY, 9)))
				{
					bEnd = false;
				}
				else if(vMap[x][y] == 0)
				{
					vMap[x][y] = 9;
					bEnd = true;
				}
			}
			catch(exception &e)
			{

			}
		}while( bEnd == false );
	}


	//Number Logic
	for(int x = 0; x < iCol; x++)
	{
		for(int y = 0; y < iRow; y++)
		{
			FBoxCheck(x, y, 9);
		}
	}
}

void clTile::AppButton(int iOffX, int iOffY)
{
	Button.x = iOffX;
	Button.y = iOffY;
	Button.h = 30;
	Button.w = 30;
	apply_surface( iOffX, iOffY, Tiles, screen, &TileClip[ 11 ] );
}

clTile::clTile()
{
	//Load the images
	Tiles = load_image( "Tiles.png");
    
    //If there was an error in loading the image
    if( Tiles == NULL )
    {
		log(__FILE__, __LINE__ , SDL_GetError() );
        log(__FILE__, __LINE__ , IMG_GetError() );
        //return false;    
    }
}

clTile::~clTile()
{
}

void clTile::BlitClip()
{
	int TileY = 0;

	for(int iTile = 0; iTile < 12; iTile++)
	{
		TileClip[ iTile ].x = TileY;
		TileClip[ iTile ].y = 0;
		TileClip[ iTile ].w = 30;
		TileClip[ iTile ].h = 30;
		TileY = TileY + 30;
	}
}

int SpotCheck(int x, int y)
{
	if(vMap[x][y] == 9)
	{
		return 2;
	}
	else
	{
		if (vMap[x][y] == 0)
		{
			return 1;
		}
		if(vMap[x][y] > 0 && vMap[x][y] < 9)
		{
			return 3;
		}
	}
	return 0;
}

bool MapControl(int SptX, int SptY, clTile Tile)
{
	
	if(bClick == false)
	{
		FirstClick(SptX, SptY);
		Equalto0(SptX, SptY, Tile);
		bClick = true;
	}
	else
	{
		if(SpotCheck(SptX, SptY) == 1)
		{
			Equalto0(SptX, SptY, Tile);
			return false;
		}

		if(SpotCheck(SptX, SptY) == 2)
		{
			return true;
		}

			if(SpotCheck(SptX, SptY) == 3)
			{
				bClicked[SptX][SptY] = true;
				apply_surface( Tile.Button.x, Tile.Button.y, Tile.Tiles, screen, &Tile.TileClip[ vMap[SptX][SptY] ] );
			
			}
			
		}

	return false;
}

bool clTile::handle_events(int ButX, int ButY, clTile Tile)
{    
	int x = 0, y = 0;
    //If a mouse button was pressed
    if( event.type == SDL_MOUSEBUTTONUP )
    {

		//Captures mouse loacation
		x = event.button.x;
		y = event.button.y;
		if( event.button.button == SDL_BUTTON_LEFT && bFlagged[ButX][ButY] == false) 
		{
			if( ( x > Button.x ) && ( x < Button.x + Button.w ) && ( y > Button.y ) && ( y < Button.y + Button.h ) )
			{
				//apply_surface( Button.x, Button.y, Tiles, screen, &TileClip[ 0 ] );
			
				return MapControl(ButY, ButX, Tile); // call y first then x will be fixed later
			
			}
		}
		if( event.button.button == SDL_BUTTON_RIGHT ) 
		{
			if(bFlagged[ButX][ButY] == false)
			{
				bFlagged[ButX][ButY] = true;
				apply_surface( Button.x, Button.y, Tiles, screen, &TileClip[ 10 ] );
			}
			else if (bFlagged[ButX][ButY] == true)
			{
				bFlagged[ButX][ButY] = false;
				apply_surface( Button.x, Button.y, Tiles, screen, &TileClip[ 11 ] );
			}
		}

        
    }
	return false;
}

