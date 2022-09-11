#include "Table.h"

Table::Table() {
    min_row_count = -1;
    rows = std::vector<Data>();
}

Table &Table::operator+=(const Data &d) {
    rows.push_back(d);
    if (min_row_count == -1 || min_row_count > d.data.size() - 1)
        min_row_count = d.data.size() - 1;
    return *this;
}

void Table::print() {
    auto syf = [](const Data &e) {e.print();};
    std::for_each(rows.begin(),rows.end(),syf);
}

Table &Table::sort(int index) {
    if (index > min_row_count) {
        std::cout<<"Indeks "<<index<<" nieprawidlowy!"<<std::endl;
        return *this;
    }

    auto cmp = [&index](Data a, Data b) {
        return (a.data[index]) < (b.data[index]);
    };

    std::sort(rows.begin(),rows.end(),cmp);
    return *this;
}

Table &Table::sortBy( bool (*fun)(const Data &, const Data &)) {
    std::sort(rows.begin(),rows.end(),fun);
    return *this;
}
