/**
 * @file CSVData.cpp
 * @author Marc S. Ressl
 * @brief Reads and writes CSV files
 * @version 0.2
 *
 * @copyright Copyright (c) 2022-2023
 *
 */

#include <fstream>

#include "CSVData.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @brief Reads a CSV file into a CSVData (list of vectors of fields).
 *
 * @param path The file to be read
 * @param data A CSVData object
 * @return true Succeeded
 * @return false Failed
 */

bool readCSV(const string path, CSVData& data)
{
    ifstream file(path);

    if (!file.is_open())
        return false;

    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    char* fileData = new char[fileSize];
    file.seekg(0);
    file.read(&fileData[0], fileSize);

    bool inQuotes = false;
    bool lastQuote = false;

    string field;
    vector<string> fields;

    for (int i = 0; i < fileSize; i++)
    {
        char c = fileData[i];

        if (lastQuote && c != '"')
            inQuotes = !inQuotes;

        if (c == '"')
        {
            if (lastQuote)
            {
                field += c;
                lastQuote = false;
            }
            else
                lastQuote = true;
        }
        else if (c == ',')
        {
            if (inQuotes)
                field += c;
            else
            {
                fields.push_back(field);
                field.clear();
            }

            lastQuote = false;
        }
        else if ((c == '\n') || (c == '\r'))
        {
            if (field.size())
                fields.push_back(field);
            field.clear();

            if (fields.size())
                data.push_back(fields);
            fields.clear();

            inQuotes = false;
            lastQuote = false;
        }
        else
        {
            field += c;
            lastQuote = false;
        }
    }

    if (field.size())
        fields.push_back(field);
    if (fields.size())
        data.push_back(fields);

    delete[] fileData;

    return true;
}
//ifstream file(path);

//if (!file.is_open())
//    return false;

//file.seekg(0, ios::end);
//int fileSize = file.tellg();
//char* fileData = new char[fileSize];
//file.seekg(0);
//file.read(&fileData[0], fileSize);

//bool inQuotes = false;
//bool lastQuote = false;

//string field;
//vector<string> fields;

//for (int i = 0; i < fileSize; i++)
//{
//    char c = fileData[i];

//    if (lastQuote && c != '"')
//        inQuotes = !inQuotes;

//    if (c == '"')
//    {
//        if (lastQuote)
//        {
//            field += c;
//            lastQuote = false;
//        }
//        else
//            lastQuote = true;
//    }
//    else if (c == ',')
//    {
//        if (inQuotes)
//            field += c;
//        else
//        {
//            fields.push_back(field);
//            field.clear();
//        }

//        lastQuote = false;
//    }
//    else if ((c == '\n') || (c == '\r'))
//    {
//        if (field.size())
//            fields.push_back(field);
//        field.clear();

//        if (fields.size())
//            data.push_back(fields);
//        fields.clear();

//        inQuotes = false;
//        lastQuote = false;
//    }
//    else
//    {
//        field += c;
//        lastQuote = false;
//    }
//}

//if (field.size())
//    fields.push_back(field);
//if (fields.size())
//    data.push_back(fields);

//delete[] fileData;

//return true;


bool loadDataSet(const string path) {

	CSVData heartCSVData;
	if (!readCSV(path, heartCSVData)) {
		cout << "ERROR WHEN READING FILE GOES BRRR" << endl;
		return false;
	}
	cout << "SUCESSFULL FILE OPENINGG GOES BRAA" << endl;
	for (auto fields : heartCSVData)
	{
		// Que hace este if?
		if (fields.size() != 2)
			continue;

		string age = fields[0];
		string sex = fields[1];
		string cp = fields[2];
		string trthps = fields[3];
		string chol = fields[4];
	}

	return true;
}



/**
 * @brief Writes a CSVData (list of vectors of fields) to a CSV file.
 *
 * @param path The file to be written
 * @param data A CSVData object
 * @return true Succeeded
 * @return false Failed
 */
bool writeCSV(const string path, CSVData& data)
{
	ofstream file(path);

	if (!file.is_open())
		return false;

	for (auto fields : data)
	{
		string line;

		bool isFirstField = true;
		for (auto field : fields)
		{
			// Replaces " with ""
			size_t pos = 0;
			while ((pos = field.find('"', pos)) != std::string::npos)
			{
				field.replace(pos, 1, "\"\"");
				pos += 2;
			}
			if (!isFirstField)
			{
				line += ',' + field;
			}
			else
			{
				isFirstField = false;
				line += '"' + field + '"';
			}
		}

		line += '\n';

		file.write(line.c_str(), line.size());

		if (!file.good())
			return false;
	}

	return true;
}