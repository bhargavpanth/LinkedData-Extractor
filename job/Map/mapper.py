
import sys
# from hdt import HDTDocument
import os

def mapper():
	# document = HDTDocument(os.path.append("../../data/LOD_a_lot_v1.hdt"))
	# standard in - file line by line
	for each_line in sys.stdin:
		data = each_line.strip().split(' ')
		
		if len(data) == 4:
			try:
				sub, pred, obj, term = data
			except Exception as e:
				pass
			else:
				pass
			finally:
				pass
			print "{0}\t{1}\t{2}".format(sub, pred, obj)

		elif len(data) == 3:
			try:
				sub, pred, obj = data
			except Exception as e:
				pass
			else:
				pass
			finally:
				pass
			print "{0}\t{1}\t{2}".format(sub, pred, obj)