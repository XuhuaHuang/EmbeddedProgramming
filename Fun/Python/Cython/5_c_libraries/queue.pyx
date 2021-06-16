# distutils: sources = c-algorithms/src/queue.c
# distutils: include_dirs = c-algorithms/src/

cimport cqueue

cdef class Queue:
	cdef cqueue.Queue* _c_queue

	'''
	Cython provides __cinit__ which is always called immediately on construction
	before CPython even considers calling __init__
	__cinit__ is the right place to initialise cdef fields of the new instance
	'''
	def __cinit__(self):
		self._c_queue = cqueue.queue_new()
		if self._c_queue is NULL:
			raise MemoryError()


	def __dealloc__(self):
		if self._c_queue is not NULL:
			cqueue.queue_free(self._c_queue)
