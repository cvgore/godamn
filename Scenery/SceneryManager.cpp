#include "SceneryManager.h"

#include "SceneryException.h"

namespace Godamn
{
	SceneryManager::SceneryManager(): m_scenes(), m_activeScene()
	{
	}

	SceneryManager::~SceneryManager()
	{
		m_activeScene.reset();

		for (auto& scene : m_scenes)
		{
			scene.reset();
		}
	}

	std::shared_ptr<Scene> SceneryManager::getActiveScene() const
	{
		return m_activeScene;
	}

	SceneryManager::SceneArray SceneryManager::getScenes() const
	{
		return m_scenes;
	}

	void SceneryManager::setActiveScene(std::shared_ptr<Scene> scene)
	{
		if (scene != nullptr && !contains(scene))
		{
			throw SceneryException("Cannot set non-existing scene as active");
		}

		m_activeScene = scene;
	}

	std::shared_ptr<Scene>& SceneryManager::newScene()
	{
		m_scenes.emplace_back(__new Scene);

		return m_scenes.back();
	}

	void SceneryManager::removeScene(std::shared_ptr<Scene> scene)
	{
		const auto it = find(scene);

		if (it != cend())
		{
			if (scene != m_activeScene)
			{
				scene.reset();
				m_scenes.erase(it);

				return;
			}

			throw SceneryException("Tried to delete active scene");
		}

		throw SceneryException("Tried to delete non existing scene");
	}

	bool SceneryManager::contains(const std::shared_ptr<Scene>& scene) const
	{
		return find(scene) != cend();
	}

	SceneryManager::SceneArray::const_iterator SceneryManager::cbegin() const
	{
		return m_scenes.cbegin();
	}

	SceneryManager::SceneArray::const_iterator SceneryManager::cend() const
	{
		return m_scenes.cend();
	}

	int32_t SceneryManager::indexOf(const std::shared_ptr<Scene>& scene) const
	{
		const auto it = find(scene);

		return it != cend() ? std::distance(cbegin(), it) : -1;
	}

	SceneryManager::SceneArray::const_iterator SceneryManager::find(const std::shared_ptr<Scene>& scene) const
	{
		return scene != nullptr ? std::find(cbegin(), cend(), scene) : cend();
	}
}
