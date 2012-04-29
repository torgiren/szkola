#ifndef __DROGA_H
#define __DROGA_H
class Droga
{
	public:
		Droga(int src, int dst, int len);
		void DodajFeromony();
		bool operator==(const Droga& droga) const;
		bool operator!=(const Droga& droga) const;
//	private:
		int itsDl;
		double itsFeromony;
		int itsMiasta[2];
};
#endif
