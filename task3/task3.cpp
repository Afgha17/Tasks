#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n, n2, n3, n4, m;
    ofstream ofs("reports.json");
    ifstream fin("tests.json");
    ifstream fin2("values.json");
    json j = json::parse(fin);
    json j2 = json::parse(fin2);

    m = j2["values"].size();
    n = j["tests"].size();
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int q = 0; q < m; q++)
        {
            if (j["tests"][i1]["id"] == j2["values"][q]["id"])
                j["tests"][i1]["value"] = j2["values"][q]["value"];
        }
        if (j["tests"][i1]["values"] != nlohmann::detail::value_t::null)
        {
            n2 = j["tests"][i1]["values"].size();
            for (int i2 = 0; i2 < n2; i2++) {
                for (int q = 0; q < m; q++)
                {
                    if (j["tests"][i1]["values"][i2]["id"] == j2["values"][q]["id"])
                        j["tests"][i1]["values"][i2]["value"] = j2["values"][q]["value"];
                }
                if (j["tests"][i1]["values"][i2] != nlohmann::detail::value_t::null)
                {
                    n3 = j["tests"][i1]["values"][i2]["values"].size();
                    for (int i3 = 0; i3 < n3; i3++) {
                        for (int q = 0; q < m; q++)
                        {
                            if (j["tests"][i1]["values"][i2]["values"][i3]["id"] == j2["values"][q]["id"])
                                j["tests"][i1]["values"][i2]["values"][i3]["value"] = j2["values"][q]["value"];
                        }
                        if (j["tests"][i1]["values"][i2]["values"][i3]["values"] != nlohmann::detail::value_t::null)
                        {
                            n4 = j["tests"][i1]["values"][i2]["values"][i3]["values"].size();
                            for (int i4 = 0; i4 < n4; i4++) {
                                for (int q = 0; q < m; q++)
                                {
                                    if (j["tests"][i1]["values"][i2]["values"][i3]["values"][i4]["id"] == j2["values"][q]["id"])
                                        j["tests"][i1]["values"][i2]["values"][i3]["values"][i4]["value"] = j2["values"][q]["value"];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ofs << j << endl;

    fin2.close();
    fin.close();
    ofs.close();


}

