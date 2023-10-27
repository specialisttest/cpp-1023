#ifndef _READONLYSTORAGE_H_
#define _READONLYSTORAGE_H_

template<class T = int, int multiplier = 1>
class ReadonlyStorage
{
	protected:
		T data;
	
	public:
		ReadonlyStorage() {}
		ReadonlyStorage(T _data) : data(_data){}
		
		T getData() const;
		/*T getData() const {
			return data;
		}*/
		
		T getMultypliedData()
		{
			return getData()*multiplier;
		}
		
		ReadonlyStorage operator +(const ReadonlyStorage& r) {
			return ReadonlyStorage<T, multiplier>(this->getData() + r.getData());
		}
};

template<typename T, int multiplier>
T ReadonlyStorage<T, multiplier>::getData() const
{
	return data;
}

typedef ReadonlyStorage<double> RSD;

class MS : RSD public ReadonlyStorage<double>
{
};

template<class T>
class ModifiableStorage : public ReadonlyStorage<T>
{
	public:
		ModifiableStorage(T _data) : ReadonlyStorage<T>(_data) {}
		
		void setData(T _data)
		{
			this->data = _data;
		}
};

class MyClass {
	public:
		MyClass operator +(const MyClass& p)
		{
			return MyClass();
		}
};

#endif