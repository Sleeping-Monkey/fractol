# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif 

#include <stdio.h>
#define MAX_SOURCE_SIZE 100000

int main(void)
{
	int ret;
	cl_platform_id platform_id;
	cl_uint	ret_num_platforms;
	cl_device_id	device_id;
	cl_uint	ret_num_devices;
	cl_context	context;
	cl_command_queue	command_queue;
	cl_program program = NULL;
	cl_kernel kernel = NULL;
	int	fd;
	const char fileName[] = "./src/kernel.cl";
	size_t source_size;
	char *source_str;
	int i;
	cl_mem memobj = NULL;
	int memLenth = 10;
	cl_int* mem = (cl_int *)malloc(sizeof(cl_int) * memLenth);


	/* получить доступные платформы */
	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);

	/* получить доступные устройства */
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);

	/* создать контекст */
	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	/* создаем команду */
	command_queue = clCreateCommandQueue(context, device_id, 0, &ret);
	fd = open(fileName, O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "Failed to load kernel.\n");
		exit(1);
	}
	source_str = (char *)malloc(MAX_SOURCE_SIZE + 1);
	source_size = read(fd, source_str, MAX_SOURCE_SIZE);
	close(fd);

	/* создать бинарник из кода программы */
	program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);

	/* скомпилировать программу */
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	/* создать кернел */
	kernel = clCreateKernel(program, "test", &ret);

	/* создать буфер */
	memobj = clCreateBuffer(context, CL_MEM_READ_WRITE, memLenth * sizeof(cl_int), NULL, &ret);

	/* записать данные в буфер */
	ret = clEnqueueWriteBuffer(command_queue, memobj, CL_TRUE, 0, memLenth * sizeof(cl_int), mem, 0, NULL, NULL);

	/* устанавливаем параметр */
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobj);

	size_t global_work_size[1] = { 10 };

	/* выполнить кернел */
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, global_work_size, NULL, 0, NULL, NULL);

	/* считать данные из буфера */
	ret = clEnqueueReadBuffer(command_queue, memobj, CL_TRUE, 0, memLenth * sizeof(float), mem, 0, NULL, NULL);
	i = 0;
	while (i < memLenth)
		printf("%d, ", mem[i++]);
	printf("\n");
	return (0);
}