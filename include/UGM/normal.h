﻿#pragma once

#include "point.h"

#include "Interfaces/IArray/ICross.h"

namespace Ubpa {
	// it's necessary to distinguish vector and normal(bivector) when transformings
	// ref
	// - PBRT p. 86-87
	// - wikipedia-bivector: https://en.wikipedia.org/wiki/Bivector
	// - https://stackoverflow.com/questions/30465573/transforming-surface-normal-vectors-and-tangent-vectors
	template<typename T>
	struct normal : SI<TemplateList<IArray1D_Util, ICross>, normal<T>, TypeList<T, Size<3>>, T> {
		using SI<TemplateList<IArray1D_Util, ICross>, normal<T>, TypeList<T, Size<3>>, T>::SI;

		inline const point<T, 2> to_sphere_texcoord() const noexcept;

		inline const vec<T, 3> to_sphere_tangent() const noexcept;
	};

	using normalf = normal<float>;

	// maybe error in editor, but no compile error
	static_assert(sizeof(normalf) == 3 * sizeof(float));
}

#include "detail/normal.inl"
