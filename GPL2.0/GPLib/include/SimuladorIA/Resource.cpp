#include "Resource.h"

Resource::Resource(int x, int y, RESOURCES tipo) :food(0), water(0), wood(0), gold(0)
{
	int minimo = atoi(File::GetValue("mínimo", "Bases", "config.inf").c_str());
	int maximo = atoi(File::GetValue("máximo", "Bases", "config.inf").c_str());
	if (tipo != BASE) capacidade = rand() %  minimo + maximo;

	this->x = x;
	this->y = y;
	this->tipo = tipo;

	ID++;
	UID = ID;
	fontes->push_back(this);
}

void Resource::descarregar(Agent *a, Base_ *b)
{
	// Se está do lado do ninho
	if (a->getX() == x && a->getY() == y)
	{
		if (tipo == BASE)
		{
			// Descarrega o agente
			food += a->getFood();
			a->food = 0;

			water += a->getWater();
			a->water = 0;

			gold += a->getGold();
			a->gold = 0;

			wood += a->getWood();
			a->wood = 0;

			// Sinaliza que ele pode visitar a última fonte novamente
			a->ultimoPontoDeColeta = 0;
			//cout << "DESCARREGAR" << endl;
			//cout << "Water:	" << water << endl;
			//cout << "Gold:	" << gold << endl;
			//cout << "Wood:	" << wood << endl;
			//cout << "Food:	" << food << endl;
			//cout << "------------------------------" << endl;
			if (food >= b->r4 && water >= b->r3 && wood >= b->r2 && gold >= b->r1)
			{
				food -= b->r4;
				water -= b->r3;
				wood -= b->r2;
				gold -= b->r1;

				// a cada agente criado o custo de produção aumenta
				b->r1 += atoi(File::GetValue("aumento gasto R1", "Recursos", "config.inf").c_str());
				b->r2 += atoi(File::GetValue("aumento gasto R2", "Recursos", "config.inf").c_str());
				b->r3 += atoi(File::GetValue("aumento gasto R3", "Recursos", "config.inf").c_str());
				b->r4 += atoi(File::GetValue("aumento gasto R4", "Recursos", "config.inf").c_str());

				b->capacidadeMinima += atoi(File::GetValue("capacidade minima", "Carga", "config.inf").c_str());
				b->vidaMinima += atoi(File::GetValue("minima", "Energia", "config.inf").c_str());
				b->agents->push_back(new Agent(x, y, b->capacidadeMinima, b->vidaMinima));
				b->qtdAgentesVivos++;

				cout << "Spawn agent " << b->agents->size() - 1 << endl;
			}
		}
	}
}

void Resource::collectResource(Agent *a)
{
	// O último ponto de coleta não pode ser o mesmo
	if (a->getUltimoPontoDeColeta() != UID)
	{
		a->setUltimoPontoDeColeta(UID);
		// Se está do lado do ninho
		if (a->getX() == x && a->getY() == y)
		{
			//cout << "Colotei " << UID << endl;
			int qtd_recurso = rand() % (a->getCapacity() / 2) + 1;
			qtd_recurso = (qtd_recurso > capacidade) ? capacidade : qtd_recurso;

			int carga = a->getFood() + a->getWater() + a->getGold() + a->getWood();

			// Verifica se a quantidade de recursos ultrapassa a capacidade do agente
			while (carga + qtd_recurso > a->getCapacity())
			{
				qtd_recurso--;
			}
			capacidade -= qtd_recurso;
			switch (tipo)
			{
			case RESOURCE_1:
				a->food += qtd_recurso;
				break;
			case BASE:
				break;
			case RESOURCE_2:
				a->water += qtd_recurso;
				break;
			case RESOURCE_3:
				a->wood += qtd_recurso;
				break;
			case RESOURCE_4:
				a->gold += qtd_recurso;
				break;
			}

		}
	}
}

RESOURCES Resource::getTipo()
{
	return tipo;
}

const int Resource::getX()
{
	return x;
}
const int Resource::getY()
{
	return y;
}
const int Resource::getCapacidade()
{
	return capacidade;
}

void Resource::setName(string name)
{
	this->name = name;
}

vector<Resource*>* Resource::fontes = new vector<Resource*>;
int Resource::ID = 0;
