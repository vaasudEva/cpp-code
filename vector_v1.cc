
#include <iostream>
#include <string>

using namespace std;

namespace msp {

template <typename T> 
class vector
{
public:
	vector(size_t cap = 1);
	~vector();

	size_t size() const { return !mPos ? 0 : mPos; }
	T &operator[](int i) const;
	const T &front() const;
	const T &back() const;
	bool empty() const;

	void push_back(const T &);
	void pop_back();

private:
	T *mElements;
	size_t mPos; 
	size_t mCap; 
};

template <typename T>
vector<T>::vector(size_t cap)
	:mElements { new T [cap] },
	 mPos { 0 },
	 mCap { cap }
{}		

template <typename T>
vector<T>::~vector()
{
	delete[] mElements;
}

template <typename T>
T &vector<T>::operator[](int i) const
{
	return mElements[i];
}

template <typename T>
const T &vector<T>::front() const
{
	return mElements[0];
}

template <typename T>
const T &vector<T>::back() const
{
	return mElements[mPos-1];
}

template <typename T>
void vector<T>::push_back(const T &item)
{
	if (size() == mCap) {
		auto newp = new T [mCap * 2];

		for (size_t i = 0; i < size(); i++)
			newp[i] = mElements[i];
		delete[] mElements;
		mElements = newp;

		mCap *= 2;
		mElements[mPos++] = item;
	} else {
		mElements[mPos++] = item;
	}
}

template <typename T>
void vector<T>::pop_back()
{
	if (!mPos) return;
	
	--mPos;
}

template <typename T>
bool vector<T>::empty() const
{
	return !mPos;
}

} // namespace msp

int main()
{
	{
		msp::vector<float> vf;
		float a[] = { 2.3, 5.4, -6., -8.6, 1.4, 1.6 };
		for (auto it : a) {
			vf.push_back(it);
			cout << "pushed " << it << endl;
		}
		cout << "vector has " << vf.size() << " elements" << endl;
		cout << "back(): " << vf.back() << endl;

		while (!vf.empty())
			vf.pop_back();

		cout << "vector empty " << endl;
	}

	{
		msp::vector<string> vs;
		string a[] = { "hare", "krishna", "narahari", "govinda", "narayana" };
		for (auto it : a) {
			vs.push_back(it);
			cout << "pushed " << it << endl;
		}
		cout << "vector has " << vs.size() << " elements" << endl;
		cout << "back(): " << vs.back() << endl;
		while (!vs.empty())
			vs.pop_back();

		cout << "vector empty " << endl;
	}

	return 0;
}

