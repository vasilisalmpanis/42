#include "../include/libftpp.hpp"

Memento::Snapshot Memento::save() {
	Snapshot snap;
	_saveToSnapshot(snap);
	return snap;

}
void	Memento::load(const Memento::Snapshot& state) {
	// error for dropping const qualifier
	_loadFromSnapshot(const_cast<Snapshot &>(state));
}

/* Snapshot */


Memento::Snapshot::Snapshot(const Snapshot &other)
{
	if (this != &other)
		*this = other;
}

Memento::Snapshot &Memento::Snapshot::operator=(const Memento::Snapshot &other)
{
	if (this != &other) {
		this->state = other.state;
	}
	return *this;
}
