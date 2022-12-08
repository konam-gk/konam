#ifndef kaNew_h
#define kaNew_h

#include <memory>

//template<typename T>
//class kaNew
//{
//	kaNew();
//public:
//
//	static std::unique_ptr<T> New()
//	{
//		struct EnableMaker : public T { using T::New(); };
//		return std::make_unique<EnableMaker>();
//	}
//};

template<typename T>
std::unique_ptr<T> kaNew(void)
{
	struct EnableMaker : public T { using T::New(); };
	return std::make_unique<EnableMaker>();
}

//template<typename T>
//class kaNew
//{
//public:
//	static kaNew add() : std::make_unique<T>{ T::New() } {}
//	static std::unique_ptr<T> New()
//	{
//		struct EnableMaker : public T { using T::New(); };
//		return std::make_unique<EnableMaker>();
//	}
//};

#endif // !kaNew_h

