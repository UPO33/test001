#pragma once

//each module must have its own API interface as $MODULENAME$_API
#define CORE_API __declspec(dllexport)


namespace ProjectName
{
	//template classes have T prefix
	
	template<typename TElement, typename TAllocator> class TArray
	{
	public:
		//forwarded types usually have T suffix
		using ElementT = TElement;
		using AllocatorT = TAllocator;
		
		//member variables have m prefix
		
		TElement* mElements;
		unsigned  mLength;
		unsigned  mCapacity;
		
		unsigned Length();
		
		//empty the array
		void Empty();
		//return true if specified index is valid
		bool IsIndexValid(unsigned index) const;
		
	
		//usually for pointer and bool arguments prefixes must be used for more clarity
		//other like i for int or n for number are not suggested
		void TestFunc0(const Apple* pNewApple, bool bIsFresh)
		{
			
		}
	};
	
	//'in' 'out' 'inout' prefixes must be used for more clarity when needed, don't use __IN and __OUT macros like Microsoft :D
	bool GetRootClass(Object* inObjects, size_t numObjects, ClassData* outClassData);
	
	
	//////////////////
	template <typename TClass> class TSharedPtr
	{
	public:
		using ClassT = TClass;
		
		bool IsValid() const { }
		
		TSharedPtr() : mPointer(nullptr) {}
		
		TClass* mPointer;
	};
	
	
	//the basic information about a user of the library
	class MODULENAME_API SimpleUser
	{
	public:	
		void PrintHisName() {}
		//return true is user is mature
		bool IsMature() const { return mAge >= 18; }
		//set the age of user
		//@age the fucking age of user #node must not be negative
		void SetAge(int age) { mAge = age; OnUserAgeChanged(); }
		
		//is called when user's age is changed
		virtual void OnUserAgeChanged() {}
		
		
	private:
		int 	mAge;
		int 	mID;
		bool 	mIsSingle;
		
		//etc
	};
	
	//this class contains information of the users on the library
	//#Note don't new this class use the GetSinglton() only
	class MODULENAME_API Library 
	{
	public:
	
		static Library* GetSinglton();
		
		TArray<UserInfo> mUsers;
		TArray<UserInfo> mUsersTemporary;
		
		//@bTemporary 	whether user is temporary or permanent 
		void AddUser(const SimpleUser* pNewUser, bool bTemporary)
		{
			//simple local var
			bool userAge = pNewUser->mAge;
			
			if(userAge > 20) //is old enough?
			{
				//#TODO not implemented yet
			}
		}
		

	}
	
	
	class ResourceManager
	{
		
	};
	
	//global variables have g prefix 
	
	//whether the engine ran in threaded mode or not
	MODULENAME_API extern bool gIsThreaded;
	//number of frames sine the start of program
	MODULENAME_API extern unsigned gFrameCount;
	//pointer to the resource manager system
	MODULENAME_API extern ResourceManager* gResourceManager;
	
	
	class ShaderMgr
	{
	public:
		//singleton pastern must be one of these functions which one u think is better?
		static ShaderMgr* Get(); 
		static ShaderMgr* GetSingleton();
		static ShaderMgr* GetInstance();
	};
	
	//also helper function for singleton is recommended.
	inline auto GShaderMgr() { return ShaderMgr::GetSingleton(); }
	
	//enums have E prefix. elements usually have 3 or 2 prefixes as follow
	enum EObjectFlag
	{
		EOF_Alive,
		EOF_Renderable,
		EOF_Tickable,
	};
	//elements of enum class sometimes need prefix
	//sometime Windows has a macro Like Circle or Box and ruin everything, ...
	enum class EShape
	{
		Circle, Box, Triangle,
	};
	
	
	class TestClass
	{
		UserInfo	mUsers;
		
		void Func0(const char* str, size_t strLen) const
		{
			//try to not use i, j, k, l for loops especially when there are many for in a for in a for
			//I use i prefix for all type of integers (signed and unsigned) but if u can't get along with it we can write n or ..?
			
			for(int iUser = 0; iUser < mNumUser; iUser++)
			{
				
			}
		}

	}
};

//never write raw code like this
void DrawPt(unsigned col);
//at least try to use structure, typedef or do something else
void DrawPoint(int rgbaColor);
void DrawPoint(Color32 color);

//don't use typedef for basic data types when ever possible (always :D),
//u don't need to do typedef float F32; instead of float; try to have portable code so that everyone can copy it somewhere else.
//all the systems have float, double, int and unsigned. we won't code for 8 bit systems my cheap phone is 64 bit :)
//I usually use unsigned or size_t for unsigned integers;

//try to use less macro amap, for instance use template function for abs min max , .. instead of macro


/*
//we must have a same namespace for the whole project ?
namesapce $ProjectName$
{
	
};

or each module must have its own namespace ?

namespace $ModuleName$
{
	
};

seems ridiculous I used to did it. it has so many disadvantages.
first of all its over namespaceing and when project grows u have to write too many 'using namespaces XXX'
and sometimes for reasons like not having enough name or emphasizing on something or defining a category or whatever
u use prefix, suffix, abbreviation, etc like the following:

class GLBuffer :{}
class GLTexture {}

so having a namesapce and having prefix both are not good idea. and if we don't have prefix or suffix it would cause many problems 
including more hard to be remembered, confusing with other classes, IntelliSence may get it wrong and give us error :()

namespace GLRenderer 
{
	class GLBuffer :{}
	class GLTexture {}
};

*/

/*
or should we use prefix ?
first of all prefixes must be as short as possible maybe one or two letters
longer code is harder to debug and even write
a good point about using namespace is when we are in the namespace we don't need to write namespace::
in contrast if we use prefix we have to write it everywhere :(

sample:

class ASDBatcher
{
	void ASDDrawLine(ASDVec3 a, ASDVec3 b, ASDColor c0 = ASDColor::WHITE, ASDColor c1 = ASDColor::WHITE);
}

namespace ASD
{
class Batcher
{
	void DrawLine(Vec3 a, Vec3 b, Color c0 = Color::WHITE, Color c1 = Color::WHITE);	
};
};

*/



