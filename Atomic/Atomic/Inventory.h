#ifndef __ATOMIC__INVENTORY__H
#define __ATOMIC__INVENTORY__H
#include <vector>
#include <functional>
#include "./Item.h"

namespace atomic {
	using ItemContainer = std::vector<atomic::Item>;
	class Inventory {
	private:
		ItemContainer m_inventory;
	public:
		Inventory() = default;
		Inventory(ItemContainer inventory)
			: m_inventory{inventory}
		{
		}

		void randomizeInventory();
		inline void addItem(const atomic::Item& item) { this->m_inventory.push_back(item); }
		[[nodiscard]] inline const ItemContainer& getInventory() const noexcept { return this->m_inventory; }
		size_t item_count() const noexcept { return this->m_inventory.size(); }

		ItemContainer::iterator begin() noexcept { return this->m_inventory.begin(); }
		ItemContainer::iterator end() noexcept { return this->m_inventory.end(); }

		// Searching / Indexing
		atomic::Item& operator[](int index) { return this->m_inventory[index]; }
		atomic::Item& findItemByName(const std::string& name);
		atomic::Item& findItemById(int assetId);
		ItemContainer itemMatch(const std::function<bool(const atomic::Item&)>& function);
	};
}

#endif