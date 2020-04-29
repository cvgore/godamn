#pragma once

#include "Scene.h"
#include <memory>
#include <vector>
namespace Godamn
{
	class SceneryManager
	{
		std::vector<std::shared_ptr<Scene>> m_scenes;
		std::shared_ptr<Scene> m_activeScene;
		
	public:
		SceneryManager();
		SceneryManager(const SceneryManager&) = delete;
		SceneryManager(SceneryManager&& other) = delete;
		SceneryManager& operator=(const SceneryManager&) = delete;
		SceneryManager& operator=(SceneryManager&&) = delete;
		~SceneryManager();

		/**
		 * @brief Returns pointer to current scene
		 */
		std::shared_ptr<Scene> getActiveScene() const;
		/**
		 * @brief Returns array of scenes
		 */
		std::vector<std::shared_ptr<Scene>> getScenes() const;
		/**
		 * @brief Sets current scene
		 */
		void setActiveScene(const std::shared_ptr<Scene>& scene);
		/**
		 * @brief Creates new scene and pushes it into array
		 */
		std::shared_ptr<Scene> newScene();
		/**
		 * @brief Removes scene from array. Only non-active scenes can be removed
		 */
		void removeScene(std::shared_ptr<Scene> scene);
		/**
		 * @brief Finds scene within array, returns -1 if not found
		 */
		int32_t indexOf(const std::shared_ptr<Scene>&) const;
		/**
		 * @brief Finds scene within array
		 */
		std::vector<std::shared_ptr<Scene>>::const_iterator find(const std::shared_ptr<Scene>& scene) const;
		/**
		 * @brief Checks if array contains scene
		 */
		bool contains(const std::shared_ptr<Scene>& scene) const;
		std::vector<std::shared_ptr<Scene>>::const_iterator cbegin() const;
		std::vector<std::shared_ptr<Scene>>::const_iterator cend() const;
	};
}
