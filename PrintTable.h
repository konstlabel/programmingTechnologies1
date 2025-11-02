#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Vector.h"

using namespace Vectors;

void printMarkdownTable(
    Vector<std::string>& headers,
    Vector<Vector<std::string>>& rows)
{

    system("cls");

    if (headers.isEmpty()) return;

    int cols = headers.size();

    Vector<int> widths;
    for (int i = 0; i < cols; ++i) {
        std::string* h = headers.get(i);
        widths.add(new int((int)h->size()));
    }

    for (auto rowIt = rows.begin(); rowIt != rows.end(); ++rowIt) {
        Vector<std::string>* row = *rowIt;
        for (int i = 0; i < cols && i < row->size(); ++i) {
            std::string* cell = row->get(i);
            int len = (int)cell->size();
            int* w = widths.get(i);
            if (len > *w) *w = len;
        }
    }

    auto printRow = [&](Vector<std::string>& row) {
        std::cout << "|";
        for (int i = 0; i < cols; ++i) {
            std::string cell = (i < row.size()) ? *(row.get(i)) : "";
            std::cout << " " << std::left << std::setw(*widths.get(i)) << cell << " |";
        }
        std::cout << "\n";
        };

    printRow(headers);

    std::cout << "|";
    for (int i = 0; i < cols; ++i)
        std::cout << std::string(*widths.get(i) + 2, '-') << "|";
    std::cout << "\n";

    for (auto rowIt = rows.begin(); rowIt != rows.end(); ++rowIt)
        printRow(*(*rowIt));

    _getch();
}

template<typename T>
void printDtos(const Vector<T>& dtos) {
    Vector<Vector<std::string>> table;

    for (auto it = dtos.begin(); it != dtos.end(); ++it) {
        T* dto = *it;
        table.add(new Vector<std::string>(dto->toPrintable()));
    }

    Vector<std::string> headers = T::headers();
    printMarkdownTable(headers, table);
}