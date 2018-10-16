#include "ZLinearTable.h"

using namespace std;

int main(void)
{
	size_t len = 0;
	ZLinearTable<int> zlt;
	for (int i = 0; i < 10; i++)
	{
		zlt.InsertElem(i, i);
	}
	zlt.GetListSize(len);
	cout << len << endl;
	cout << zlt << endl;
	zlt.ShowAllElem();
	system("pause");
	return 0;
}