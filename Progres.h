#pragma once

class Progres {

	Progres()
	{
		std::cout << "Just for test!!";
	}

	int getConsum()
	{
		return this->consumul;
	}
	double getProteineMIN()
	{
		return this->proteineMIN;
	}
	double getProteineMAX()
	{
		return this->proteineMAX;
	}
	double getCarbohidratiMIN()
	{
		return this->carbohidratiMIN;
	}
	double getCarbohidratiMAX()
	{
		return this->carbohidratiMAX;
	}
	
	double getGrasimiMIN()
	{
		return this->grasimiMIN;
	}
	double getGrasimiMAX()
	{
		return this->grasimiMAX;
	}

	void setConsum(int consum)
	{
		 this->consumul = consum;
	}
	void setProteineMIN(double proteineMIN)
	{
		this->proteineMIN = proteineMIN;
	}
	void setProteineMAX(double proteineMAX)
	{
		 this->proteineMAX = proteineMAX;
	}
	void setCarbohidratiMIN(double carbohidratiMIN)
	{
		this->carbohidratiMIN = carbohidratiMIN;
	}
	void setCarbohidratiMAX(double carbohidratiMax)
	{
		this->carbohidratiMAX = carbohidratiMAX;
	}

	void getGrasimiMIN(double grasimiMIN)
	{
		this->grasimiMIN = grasimiMIN;
	}
	void getGrasimiMAX(double grasimiMAX)
	{
		this->grasimiMAX = grasimiMAX;
	}

private:
	int consumul;
	double proteineMIN, proteineMAX;
	double carbohidratiMIN, carbohidratiMAX;
	double grasimiMIN, grasimiMAX;
	
};