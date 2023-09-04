#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map<string, string> m{ { "08","冰冰"}, {"03","西施"}, {"01","蜜蜜"}, {"07","金莲"}, {"05","西瓜"}};
	cout << "m[08]=" << m["08"] << endl;	// 显示key为8的元素的value
	cout << "m[09]=" << m["09"] << endl;	// 显示key为9的元素的value。Key为9的元素不存在，将添加新的键值对,key="09",value为空

	m["07"] = "花花";	// 把key为7的元素的value修改为花花
	m["12"] = "小巧";	// 添加新的键值对

	for (auto& val : m) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
}