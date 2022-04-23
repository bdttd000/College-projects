#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Pie;

class JakubCake {
protected:
	double amount;
	string flavour;
public:
	JakubCake(double amount, string flavour) : amount(amount), flavour(flavour) {}
	~JakubCake() {}

	friend ostream& operator<<(ostream& out, const Pie& ob);
	bool checkFlavour(string cakeFlavour)
	{
		return cakeFlavour == this->flavour;
	}
};
class WartakDressing {
protected:
	string flavour;
	string color;
public:
	WartakDressing(string flavour, string color) : flavour(flavour), color(color) {}
	~WartakDressing() {}

	friend ostream& operator<<(ostream& out, const Pie& ob);
};
class Pie : public JakubCake, public WartakDressing {
	double weight;
public:
	Pie(double weight, string dressingFlavour, string dressingColor, double cakeAmount, string cakeFlavour)
		: JakubCake(cakeAmount, cakeFlavour), WartakDressing(dressingFlavour, dressingColor), weight(weight) {}

	friend bool checkWeight(const Pie& ob1, const Pie& ob2);
	friend ostream& operator<<(ostream& out, const Pie& ob);

	template<typename returnType, typename inputType>
	friend returnType totalPower(const inputType& input);
};

ostream& operator<<(ostream& out, const Pie& ob)
{
	out << ((JakubCake&)ob).flavour << " " << ob.amount << " " << ((WartakDressing&)ob).flavour << " " << ob.color << " " << ob.weight << endl;
	return out;
}

void printToScreen(const vector<Pie>& list, const string& text)
{
	cout << text << endl;
	for (auto x : list)
	{
		cout << x;
	}
	cout << endl;
}

bool checkWeight(const Pie& ob1, const Pie& ob2)
{
	return ob1.weight > ob2.weight;
}

template<typename returnType, typename inputType>
returnType totalPower(const inputType& input)
{
	double sum = 0;
	for (auto x : input)
	{
		sum += x.weight - x.amount;
	}
	return (returnType)(sum / input.size());
}


void aboutMe()
{
	cout << "Jakub Wartak nr albumu 132822" << endl << endl;
}

int main() {
	aboutMe();
	vector<Pie> itemsList;
	itemsList.push_back(Pie(1200, "waniliowy", "zielony", 1000, "czekoladowe"));
	itemsList.push_back(Pie(1500, "migdalowy", "niebieski", 1200, "orzechowe"));
	itemsList.push_back(Pie(1100, "smietanowa chmurka", "blekitny", 900, "kakaowe"));
	itemsList.push_back(Pie(1400, "gorzkie kakao", "czarny", 1125, "waniliowe"));
	itemsList.push_back(Pie(1000, "slony karmel", "rdzawy", 520, "kokosowe"));
	printToScreen(itemsList, "Oryginal");

	cout << "Points for this person: " << totalPower<float, vector<Pie>>(itemsList) << endl << endl;

	sort(itemsList.begin(), itemsList.end(), checkWeight);
	printToScreen(itemsList, "Sorted");

	for (size_t i = 0; i < itemsList.size(); ++i)
	{
		if (itemsList[i].checkFlavour("kokosowe"))
		{
			itemsList.erase(itemsList.begin() + i);
			--i;
		}
	}
	printToScreen(itemsList, "End");

	return 0;
}
