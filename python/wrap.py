from functools import wraps

def rerun(tries=3):
	def deco_rerun(f):
		@wraps(f)
		def f_rerun(*args, **kwargs):
			for i in range(tries):
				f(*args, **kwargs)
		return f_rerun
	return deco_rerun

@rerun(tries=2)
def hello():
	print("hello")

if __name__ == '__main__':
	hello()	
