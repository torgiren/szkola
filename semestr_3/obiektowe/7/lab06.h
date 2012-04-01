#ifndef __INTTAB__
#define __INTTAB__
class IntTab
{
	public:
		IntTab(int size=0);
		IntTab(const IntTab& clone);
		~IntTab();
		int& operator()(int num) const;
		void operator=(const IntTab& b);
		IntTab operator-() const;
		IntTab operator-(IntTab& a) const;
		void print() const;
	private:
		int itsSize;
		int* itsTab;
};
#endif
