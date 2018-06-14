# LANG='en_GB.UTF-8'

import sys
# from hdt import HDTDocument

def mapper():
	# document = HDTDocument(os.path.append("../../data/LOD_a_lot_v1.hdt"))
	# standard in - file line by line
	for each_line in sys.stdin:
		data = encoded_line.strip().split(' ')
		if len(data) == 4:
			try:
				sub, pred, obj, term = data
			except Exception as e:
				pass
			else:
				print "{0}\t{1}\t{2}".format(sub, pred, obj)
			finally:
				pass

		elif len(data) == 3:
			try:
				sub, pred, obj = data
			except Exception as e:
				pass
			else:
				print "{0}\t{1}\t{2}".format(sub, pred, obj)
			finally:
				pass
			# print "{0}\t{1}\t{2}".format(sub, pred, obj)

