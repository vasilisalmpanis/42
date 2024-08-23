// mememento -> stores snapshots -> new Snapshot
// has snapshot -> subclass
// probably has vector of snapshots *. on save its added to back
// on load it is restored to object T and deleted from vector.
// destructot deletes all snapshots
// mement snapshot will be written in bytes from DataBuffer
// so we can easily serialize and deserialize an object
//
#pragma once
#include "libftpp.hpp"

class Memento {
	public:
		Memento() = default;
		~Memento() = default;
		Memento(const Memento &) = delete;
		Memento &operator=(const Memento &) = delete;
		class Snapshot {
			public:
				Snapshot() = default;
				~Snapshot() = default;
				Snapshot(const Snapshot &other);
				Snapshot &operator=(const Snapshot &other);
				template<typename T>
				Snapshot &operator<<(const T &data);
				template<typename T>
				Snapshot &operator>>(T &data);
			private:
				friend class Memento;
				DataBuffer state;
		};
		Snapshot	save();
		void		load(const Memento::Snapshot& state);
	protected:
		virtual void _saveToSnapshot(Snapshot & snapshotToFill) = 0;
		virtual void _loadFromSnapshot(Snapshot & snapshotToFill) = 0;
};

template<typename T>
Memento::Snapshot &Memento::Snapshot::operator<<(const T &data) {
		state << data;
		return *this;
}

template<typename T>
Memento::Snapshot &Memento::Snapshot::operator>>(T &data) {
		state >> data;
		return *this;
}

