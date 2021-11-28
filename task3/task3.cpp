#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"


using json = nlohmann::json;
using namespace std;

void func(json& values, json& tests)
{
    for (auto& test : tests)
    {
        for (auto& value : values)
        {
            if (test["id"] == value["id"])
                test["value"] = value["value"];
            if (test["values"] != nlohmann::detail::value_t::null)
                func(values, test["values"]);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "ru");

    ofstream ofs("reports.json");
    ifstream fin("tests.json");
    ifstream fin2("values.json");
    json tests = json::parse(fin);
    json values = json::parse(fin2);

    func(values["values"], tests["tests"]);
    ofs << tests << endl;

    fin2.close();
    fin.close();
    ofs.close();


}
