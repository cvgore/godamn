#pragma once

#include <guiddef.h>
#include <map>
#include <string>
#include "../Foundation/Object.h"
#include "../Utils/Utils.h"

#define CONFIGURE_ENTITY(entityClass, ...) \
	std::pair<StoreKey, StoreVal>(#entityClass, StoreVal __VA_ARGS__)

#define BEGIN_CONFIGURE() m_store = StoreMap({
#define END_CONFIGURE() \
	});

namespace Godamn
{
	template<typename T>
	class Store : public Object
	{
	public:
		typedef T StoreVal;
		typedef std::string StoreKey;
		typedef std::map<StoreKey, StoreVal> StoreMap;

	protected:
		StoreMap m_store;

	public:
		Store(): m_store()
		{}

		Store<T>& operator=(Store<T> store)
		{
			return Store(store.m_store);
		}

		T get(const std::string key) const
		{
			return m_store.at(key);
		}

		T get(const uint16_t key) const
		{
			return m_store.at(std::to_string(key));
		}

		T operator[](const std::string key) const
		{
			return get(key);
		}

		T operator[](const uint16_t key) const
		{
			return get(key);
		}

	protected:
		Store(Store::StoreMap map)
		{
			m_store = map;
		}
	};
}
