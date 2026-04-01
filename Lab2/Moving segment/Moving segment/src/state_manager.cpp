#include "state_manager.hpp"

engine::StateManager::StateManager() : m_add(false), m_replace(false), m_remove(false) {}

engine::StateManager::~StateManager() {}

void engine::StateManager::Add(std::unique_ptr<State> toAdd, bool replace)
{
	m_add = true;
	m_newState = std::move(toAdd);

	m_replace = replace;
}

void engine::StateManager::PopCurrent()
{
	m_remove = true;
}

void engine::StateManager::ProcessStateChange()
{
	if (m_remove && (!m_stateStack.empty()))
	{
		m_stateStack.pop();

		if (!m_stateStack.empty())
			m_stateStack.top()->Start();

		m_remove = false;
	}

	if (m_add)
	{
		if (m_replace && (!m_stateStack.empty()))
		{
			m_stateStack.pop();
			m_replace = false;
		}

		if (!m_stateStack.empty())
			m_stateStack.top()->Pause();

		m_stateStack.emplace(std::move(m_newState));
		m_stateStack.top()->Initialize();
		m_stateStack.top()->Start();
		m_add = false;
	}
}

std::unique_ptr<engine::State>& engine::StateManager::GetCurrent()
{
	return m_stateStack.top();
}