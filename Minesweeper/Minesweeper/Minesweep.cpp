#include <string>
#include <sstream>
#include <fstream>
#include "SDL_ttf.h"
#include "Map.h"

//The font that's going to be used
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };

SDL_Rect Secs[12];

// Tile[yAxis][xAxis]

//File stream for the game log.
std::ofstream logger( "log.txt" );


void log( std::string file, int line, std::string seconds = "" )
{
    //Write seconds to file
    logger << file << ", " << line << ":" << seconds << "\n";

    //Flush the buffer
    logger.flush();
}

void log( std::string seconds = "" )
{
    //Write seconds to file
    logger << seconds << std::endl;

    //Flush the buffer
    logger.flush();
}

SDL_Surface *load_image( std::string filename ) 
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

	//Load the image
    loadedImage = IMG_Load( filename.c_str() );

	//If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
	else
	{
		log(__FILE__, __LINE__ , SDL_GetError() );
        log(__FILE__, __LINE__ , IMG_GetError() );
	}

	 //If the image was optimized just fine
       if( optimizedImage != NULL ) 
	{ 
		//Return the optimized image
		return optimizedImage;
	}
	   else
		   return NULL;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ) 
{ 
	//Holds offsets 
	SDL_Rect offset; 
	//Get offsets 
	offset.x = x; 
	offset.y = y; 
	//Blit 
	SDL_BlitSurface( source, clip, destination, &offset ); 
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
		log(__FILE__, __LINE__ , SDL_GetError() );
        log(__FILE__, __LINE__ , IMG_GetError() );
        return false;    
    }

	//Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
		log(__FILE__, __LINE__ , SDL_GetError() );
        log(__FILE__, __LINE__ , IMG_GetError() );
        return false;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "Minesweeper", NULL );
    
    //If everything initialized fine
    return true;
}

void clean_up()
{  
	SDL_FreeSurface( screen );
    
    //Close the font that was used
    TTF_CloseFont( font );
    
    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit(); 
}

// Empty Space Checcker
void Equalto0(int SptX, int SptY,  clTile Tile)
{
	int x = SptX;
	int y = SptY;

	if( x >= 0 && x < iCol && y >= 0 && y < iRow )
	{
		if(vMap[x][y] == 9)
		{
		}
		else if(bClicked[x][y] == false && bFlagged[x][y] == false)
		{
			bClicked[x][y] = true;

			//Bottom
			if(vMap[x][y] == 9)
			{
			}
			else if(++x > (iCol - 1))
			{
				--x;
			}
			else
			{
				if(vMap[x][y] >= 1 && vMap[x][y] < 9) 
				{
					bClicked[x][y] = true;
					--x;
				}
				else
				{
					Equalto0(x, y, Tile);
					--x;
				}
			}
		

			// top
			if(vMap[x][y] == 9)
			{
			}
			else if(--x < 0)
			{
				++x;
			}
			else
			{
				if(vMap[x][y] >= 1 && vMap[x][y] < 9) 
				{
					bClicked[x][y] = true;
					++x;
				}
				else
				{
					Equalto0(x, y, Tile);
					++x;
				}
			}
		
			// left
			if(vMap[x][y] == 9)
			{
			}
			else if(--y < 0)
			{
				++y;
			}
			else
			{
				if(vMap[x][y] >= 1 && vMap[x][y] < 9) 
				{
					bClicked[x][y] = true;
					y++;
				}
				else
				{
					Equalto0(x, y, Tile);
					y++;
				}
			}
		

			// right
			if(vMap[x][y] == 9)
			{
			}
			else if(++y > (iRow - 1))
			{
				--y;
			}
			else
			{
				if(vMap[x][y] >= 1 && vMap[x][y] < 9) 
				{
					bClicked[x][y] = true;
					--y;
				}
				else
				{
					Equalto0(x, y, Tile);
					--y;
				}
			}

			// Top left Corner
			if(vMap[x][y] == 9)
			{
			}
			else if(vMap[x][y] == 9)
			{
			}
			else if(--x < 0)
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
					if(vMap[--x][--y] >= 1 && vMap[x][y] < 9 ) 
					{
						bClicked[x][y] = true;
						++x;
						++y;
					}
					else
					{
						Equalto0(x, y, Tile);
						++x;
						++y;
					}
				}
			}
		

			// Top right corner
			if(vMap[x][y] == 9)
			{
			}
			else if(--x < 0)
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
					if(vMap[--x][++y] >= 1 && vMap[x][y] < 9 ) 
					{
						bClicked[x][y] = true;
						++x;
						--y;
					}
					else
					{
						Equalto0(x, y, Tile);
						++x;
						--y;
					}
				}
			}

			// Bottom right corner
			if(vMap[x][y] == 9)
			{
			}
			else if(++x > (iCol - 1))
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
					if(vMap[++x][++y] >= 1 && vMap[x][y] < 9 ) 
					{
						bClicked[x][y] = true;
						--x;
						--y;
					}
					else
					{
						Equalto0(x, y, Tile);
						--x;
						--y;
					}
				}
			}

			// Bottom Left corner
			if(vMap[x][y] == 9)
			{
			}
			else if(++x > (iCol - 1))
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
					if(vMap[++x][--y] >= 1 && vMap[x][y] < 9 ) 
					{
						bClicked[x][y] = true;
						--x;
						++y;
					}
					else
					{
						Equalto0(x, y, Tile);
						--x;
						++y;
					}
				}
			}

	}
	
			
	}
}

void load_files()
{
	seconds = load_image("420.png");
	int yOffset = 253;
	for(int iSec = 0; iSec < 12; iSec++)
	{
		Secs[iSec].x = 0;
		Secs[iSec].y = yOffset;
		Secs[iSec].h = 23;
		Secs[iSec].w = 13;
		yOffset -= 23;
	}
}

void SetTime(Uint32 start)
{
	int getTime = SDL_GetTicks() - start;
	//The timer's time as a string
	if(getTime % 1000 == 0)
	{
		std::stringstream time;
		getTime /= 1000;
		
		////Convert the timer's time to a string
		time << getTime;
		string int1;
		string int2;
		string int3;
		int Time1;
		int Time2;
		int Time3;

		if(getTime > 9)
		{
			//break int apart
			if(getTime < 100)
			{
				int1 = time.str().c_str()[0];
				Time1 = atoi(int1.c_str());

				int2 = time.str().c_str()[1];
				Time2 = atoi(int2.c_str());

				apply_surface( 0, 15, seconds, screen, &Secs[ Time1 ] );
				apply_surface( 13, 15, seconds, screen, &Secs[ Time2 ] );
			}
			else if(getTime < 1000)
			{
				int1 = time.str().c_str()[0];
				Time1 = atoi(int1.c_str());

				int2 = time.str().c_str()[1];
				Time2 = atoi(int2.c_str());

				int3 = time.str().c_str()[2];
				Time3 = atoi(int3.c_str());

				apply_surface( 0, 15, seconds, screen, &Secs[ Time1 ] );
				apply_surface( 13, 15, seconds, screen, &Secs[ Time2 ] );
				apply_surface( 26, 15, seconds, screen, &Secs[ Time3 ] );
			}
		}
		else
		{
			apply_surface( 0, 15, seconds, screen, &Secs[ getTime ] );
		}
		
        
	}
}

int main( int argc, char* args[] )
{
	log("Initializing");
	//Initialize
	if( init() == false )
	{
		return 1;    
	}
	log("Loading Files");
	load_files();


	//Open the font
    font = TTF_OpenFont( "DejaVuSansMono.ttf", 10);
	

	//The timer starting time
    Uint32 start = 0;

    //The timer start/stop flag
    bool running = true;
	
	bool bEnd = false;

	log("Starting Game loop");
	while(bEnd == false)
	{
		//Make sure the program waits for a quit
		bool quit = false;
		bClick = false;
    
		
 
		//Fill the screen white
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

		// initialize button array
		//-----------------------------------------------------------------------------------------
		bClicked.resize(iCol, vector<bool>(iRow));
		bFlagged.resize(iCol, vector<bool>(iRow));
		for(int x = 0; x < iCol; x++)
		{
			for(int y = 0; y < iRow; y++)
			{
				bClicked[x][y] = false;
				bFlagged[x][y] = false;
			}
		}

		clTile **Tile;
		Tile = new class clTile*[iCol];
		int xOff = -30, yOff = 30;
		for( int row = 0; row < iRow; row++ )
		{
			Tile[row] = new class clTile[iRow];
			yOff = yOff + 30;

			for( int col = 0; col < iCol; col++ )
			{
				xOff = xOff + 30;
				Tile[row][col].BlitClip();
				Tile[row][col].AppButton(xOff, yOff);
			}
			xOff = -30;
		}



		//-----------------------------------------------------------------------------------------

		bool Bomb = false;
		//While the user hasn't quit
		Tile[3][7];
		Tile[16][30];
		while( quit == false )
		{
			 //if there's an event to handle
		   if( SDL_PollEvent( &event ) )
			{

				//Finds button loaction
				//////////////////////////////////////////////////////
				if( event.type != SDL_QUIT )
				{
					//Captures mouse loacation
					int ix = event.button.x;
					int iy = event.button.y;
				
					// calculatates modulo of number ex 147 % 30 = 27
					int remainderx = ix % 30;
					int remaindery = iy % 30;

					// if modulo is 0 then the number is a multiple of 30
					if (remainderx == 0)
					{
					}
					else 
					{
						// if its not 0 then subtract the modulo from original number to 
						// round down to nearest multiple of thirty
						ix = ix - remainderx; // ex. 147 -27 = 30
					}
					//do the same for y
					if(remaindery == 0)
					{
					}
					else
						iy = iy - remaindery;

					// now divede by thirty to find button
					int Butx = ix / 30;
					int Buty = (iy / 30) - 2;

					if(bClick == false)
					{
						//Start the timer
						start = SDL_GetTicks();
					}

					if(Butx >= 0 && Butx < iCol && Buty >= 0 && Buty < iRow)
					{
						quit = Tile[Buty][Butx].handle_events(Butx, Buty,Tile[Buty][Butx]);
						Bomb = quit;
					}
					
					
					/////////////////////////////////////////////////////
					if(quit == false)
					{
						for(int ChkX = 0;ChkX < iRow; ChkX++)
						{
							for(int ChkY = 0; ChkY < iCol; ChkY++)
							{
								if(bClicked[ChkY][ChkX] == true)
								{
									apply_surface( 
									Tile[ChkY][ChkX].Button.x, 
									Tile[ChkY][ChkX].Button.y, 
									Tile[ChkY][ChkX].Tiles,
									screen,
									&Tile[ChkY][ChkX].TileClip[ vMap[ChkY][ChkX] ] );
								}
							}
						}
					}
					else
					{
						for(int ChkX = 0; ChkX < iCol; ChkX++)
						{
							for(int ChkY = 0; ChkY < iRow; ChkY++)
							{
								if(vMap[ChkY][ChkX] == 9)
								{
									apply_surface( 
									Tile[ChkY][ChkX].Button.x, 
									Tile[ChkY][ChkX].Button.y, 
									Tile[ChkY][ChkX].Tiles,
									screen,
									&Tile[ChkY][ChkX].TileClip[ 9 ] );
								}
							}
						}
						
						vMap.clear();
						bClicked.clear();
						bClick = false;
					}

				}

				



				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
				{
					//Quit the program
					quit = true;
					bEnd = true;
					vMap.clear();
					bClicked.clear();
				}    
			}

			SetTime(start);
        

			//Update the screen
			if( SDL_Flip( screen ) == -1 )
			{
				return 1;    
			}
			if(Bomb == true)
			{
				SDL_Delay( 1500 );
			}
			
		}

		//Close log file
		logger.close();
	
		
	}

	//Free the surface and quit SDL
	clean_up();
    return 0;    
}