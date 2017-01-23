#ifndef MAP_H
#define MAP_H	
	
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
using namespace std;

	
	//The surfaces that will be used
	__declspec(selectany) SDL_Surface *screen = NULL;
	__declspec(selectany) SDL_Surface *seconds = NULL;

	//The event structure that will be used
	__declspec(selectany) SDL_Event event;

	// various functions
	void apply_surface( int, int, SDL_Surface*, SDL_Surface*, SDL_Rect* );
	SDL_Surface *load_image( string );
	void log( string, int,string );
	void log( string );

	//Game vairiables
	__declspec(selectany) int iRow = 9;
	__declspec(selectany) int iCol = 9;
	__declspec(selectany) int iMaxTile = iRow * iCol;

	//Screen Propertys
	__declspec(selectany) int SCREEN_WIDTH = 30 * iCol;
	__declspec(selectany) int SCREEN_HEIGHT = (30 * iRow) + 60;
	__declspec(selectany) int SCREEN_BPP = 32;


	
	__declspec(selectany) int MineMax;
	__declspec(selectany) std::vector<std::vector<int> > vMap;
	void FirstClick(int, int);
	int SpotCheck(int, int);
	void FBoxCheck(int, int, int);
	bool BoxCheck(int, int, int);
			
	

	__declspec(selectany) vector < vector<bool> > bClicked;
	__declspec(selectany) vector < vector<bool> > bFlagged;
	__declspec(selectany) bool bClick;
	class clTile
	{
		public:
			SDL_Surface *Tiles;
			//The portions of the sprite map to be blitted 
			SDL_Rect TileClip[ 12 ];
			SDL_Rect Button;
			clTile();
			~clTile();
			void AppButton(int, int);
			bool handle_events(int, int, clTile);
			void show();
			void BlitClip();
	};

	void Equalto0(int, int, clTile);

#endif
