//
// C00205321
// Keith Wilson
// C00204076
// Brandon Seah-Dempsey
// Started at 14:35 8 Feburary 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef IDENTIFIERS_H
#define IDENTIFIERS_H

//
namespace Actions
{
	enum ID
	{
		Push,
		Pop,
		Clear,
	};
}

//
namespace ComponentTypes
{
	enum Type
	{
	};
}

//
namespace KeyboardID
{
	enum ID
	{
		SPACE,
		W,
		Uparrow
	};
}


//
namespace SceneID
{
	enum ID
	{
		None,
		Title,
		Game,
		Gameover,
		Multiplayer,
	};
}

//
namespace NetworkScenes
{
	enum ID
	{
		Connect,
		Game,
		Disconnect,
	};
}

//
namespace TextureID
{
	enum ID
	{
		
	};
}

//
namespace SoundEffectID
{
	enum ID
	{
		
	};
}

//
namespace MusicID
{
	enum ID
	{
		Theme,
	};
}


#endif // !IDENTIFIERS_H
