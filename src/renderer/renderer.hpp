#include "renderer/mesh.hpp"
#include "renderer/program.hpp"
#include "dom.hpp"
#include "glHelper.hpp"
#include <glm/glm.hpp>


namespace photon::renderer
{
	template<typename...T>
	void draw(const program& shaderProgram, const mesh<T...>& mesh)
	{
		shaderProgram.bind();
		mesh.bind();
		GLC(glDrawElements(
			GL_TRIANGLES,
			mesh.getIndexCount(),
			GL_UNSIGNED_INT,
			(void*)0
		));
		shaderProgram.unbind();
		mesh.unbind();
	}
	mesh<
		glm::vec2,
		glm::float32,
		std::array<glm::vec2,4> ,
		std::array<glm::float32,4> ,
		std::array<glm::vec4,4>,
		glm::vec4
	> domToMesh(const _dom& dom);
} // namespace photon::renderer
