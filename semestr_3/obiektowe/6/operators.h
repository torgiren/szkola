/**
operator wczytywanie Kwadraru
*/
istream& operator>>(istream& strm,Kwadrat& element)
{
	cout<<"Prosze o podanie dl. boku"<<endl;
	strm>>element.itsA;
	return strm;
};
/**
operator wczytywania Prostokata
*/
istream& operator>>(istream& strm,Prostokat& element)
{
	cout<<"Prosze o podanie 2 bokow"<<endl;
	strm>>element.itsA>>element.itsB;
	return strm;
};
istream& operator>>(istream& strm,Kolo& element)
{
	cout<<"Prosze o podanie R"<<endl;
	strm>>element.itsR;
	return strm;
};
istream& operator>>(istream& strm,Trojkat& element)
{
	cout<<"Prosze o podanie dlugosci 3 bokow"<<endl;
	strm>>element.itsA>>element.itsB>>element.itsC;
	return strm;
};
ostream& operator<<(ostream& strm, Kwadrat& element)
{
	strm<<"Pole to: "<<element.RetPole()<<", a obwod to: "<<element.RetObwod()<<endl;
	return strm;
};
ostream& operator<<(ostream& strm, Prostokat& element)
{
	strm<<"Pole to: "<<element.RetPole()<<", a obwod to: "<<element.RetObwod()<<endl;
	return strm;
};
ostream& operator<<(ostream& strm, Kolo& element)
{
	strm<<"Pole to: "<<element.RetPole()<<", a obwod to: "<<element.RetObwod()<<endl;
	return strm;
};
ostream& operator<<(ostream& strm, Trojkat& element)
{
	strm<<"Pole to: "<<element.RetPole()<<", a obwod to: "<<element.RetObwod()<<endl;
	return strm;
};
