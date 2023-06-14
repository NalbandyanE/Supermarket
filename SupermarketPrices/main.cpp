#include "supermarket.h"
#include <iostream>

int main() {
	PricingScheme ps(PricingScheme::PricingSchemeType::BUY_TWO_GET_ONE_FREE, 25);
	PricingScheme ps1(PricingScheme::PricingSchemeType::PRICE_PER_WEIGHT, 40);
	PricingScheme ps2(PricingScheme::PricingSchemeType::THREE_FOR_DOLLAR, 30);
	PricingScheme ps3(PricingScheme::PricingSchemeType::SIMPLE, 15);
	Supermarket SAS;
	Product p1("bread", 250, 13, ps3);
	Product p2("egg", 50, 40, ps2);
	Product p3("sugar", 400, 1500.0, ps1);
	Product p4("apple", 350, 3000.0, ps1);
	Product p5("chips", 600, 15, ps3);
	SAS.addProduct(p1);
	SAS.addProduct(p2);
	SAS.addProduct(p3);
	SAS.addProduct(p4);
	SAS.addProduct(p5);
	SAS.displayProducts();
	SAS.updateProductName(p2, "knife");
	SAS.updateProductPrice(p1, 300);
	SAS.deleteProduct(p4);
	SAS.displayProducts();
	SAS.displayInFile();

	return 0;
}