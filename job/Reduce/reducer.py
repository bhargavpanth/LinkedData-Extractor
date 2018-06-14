
import sys
from urlparse import urlparse


def reducer():

	key = None
	counter = 0

	for each_line in sys.stdin:

		data = each_line.strip().split('\t')

		if len(data) != 3:
			continue

		Subject, Predicate, Object = data

		print "{0}\t{1}\t{2}".format(Subject, Predicate, Object)

	# 	subject_domain_name = return_url(Subject)

	# 	if subject_domain_name != False:
	# 		if key and key != subject_domain_name:
	# 			print "{0}\t{1}\t{2}\t{3}".format(key, counter, subject_domain_name, Object)
	# 			counter = 0

	# 	key = subject_domain_name
	# 	counter += 1

	# if key != None:
	# 	print "{0}\t{1}\t{2}\t{3}".format(key, counter, subject_domain_name, Object)


def return_url(url):
	if url.startswith('_'):
		pass
	else:
		try:
			parsed_uri = urlparse(url)
			domain = '{uri.scheme}://{uri.netloc}/'.format(uri=parsed_uri)
		except Exception as e:
			return False
		else:
			return domain
	
	
