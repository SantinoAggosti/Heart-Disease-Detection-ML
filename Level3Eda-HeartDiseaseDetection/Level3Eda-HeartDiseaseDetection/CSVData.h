/**
 * @file CSVData.h
 * @author Marc S. Ressl
 * @brief Reads and writes CSV files
 * @version 0.2
 *
 * @copyright Copyright (c) 2022-2023
 *
 */

#ifndef _CSVDATA_H
#define _CSVDATA_H

#include <list>
#include <string>
#include <vector>
#include "dataSet.h"

using namespace std;

struct Header
{
    string Header;
};

typedef list<Header> Headers;
typedef list<vector<string>> CSVData;

bool readCSV(const string path, CSVData& data);
bool writeCSV(const string path, CSVData& data);
bool loadDataSet(const string path);

#endif
