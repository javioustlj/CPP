
struct Sales_data {
    std::string bookNo;
    unsigned unites_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;
    if (read(cin, total))
