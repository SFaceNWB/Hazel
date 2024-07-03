#include "hzpch.h"
#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Hazel {

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		:m_ProjectionMatrix(glm::ortho(left,right,bottom,top,-1.0f,1.0f)),m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	//transform = translate * rotate * scale
	//局部空间 * model模型矩阵 = 世界空间
	//世界空间 * 视图矩阵(viewMatrix) =观察空间
	//观察空间 * 投影矩阵(projectionMatrix) = 裁剪空间
	void OrthographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 transform =glm::translate(glm::mat4(1.0f), m_Position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

}