
cmake_minimum_required (VERSION 3.12)
add_executable(
	VectorFillerProjekt
		../main.cpp
		bootstrap/application_starter.h bootstrap/application_starter.h time/stopwatch.h io/writer.h generators/generator.h collections/vector_factory.h clients/client_impl.h time/impl/stopwatch_impl.h)