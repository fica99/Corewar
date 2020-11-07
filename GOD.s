# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    GOD.s                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 17:09:23 by aashara-          #+#    #+#              #
#    Updated: 2020/11/07 17:09:27 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.name				"GOD"
.comment			"And God said and there was light"

		sti		r1,		%:alive,		%1
		ld		%75,	r13
		aff		r13
		fork	%:init_forward
		live	%1337

init_backward:
		ld		%880,			r5		# 7
		ld		%50327043,		r6		# 7
		ld		%1879310335,	r7		# 7
		ld		%16777216,		r8		# 7
		ld		%17432543,		r9		# 7
		st		r5,				-80		# 5
		st		r6,				-81		# 5
		st		r7,				-82		# 5
		st		r8,				-83		# 5
		st		r9,				-84		# 5
		fork	%:r_p5					# 3
		live	%42						# 5
		fork	%:r_p4					# 3
		live	%42						# 5
		fork	%:r_p3					# 3
		live	%42						# 5
		fork	%:r_p2					# 3
		live	%42						# 5
		fork	%:r_p1					# 3
		ld		%0,				r2		# 7 carry = 1
		zjmp	%:init_forward			# 3

r_p1:
		ld		%57672447,		r2		# 7
		ld		%4060311555,	r3		# 7
		ld		%0,				r4		# 7
r_p1_2:
		live	%42						# 5
		fork	%:r_p1_2				# 3
		zjmp	%-177					# 3

r_p2:
		live	%42						# 5
		ld		%3993202691,	r2		# 7
		ld		%4127420419,	r3		# 7
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
r_p2_2:
		live	%42						# 5
		fork	%:r_p2_2				# 3
		zjmp	%-222					# 3

r_p3:
		live	%42						# 5
		ld		%4294902016,	r2		# 7
		ld		%4177752067,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p3_2:
		live	%42						# 5
		fork	%:r_p3_2				# 3
		zjmp	%-280					# 3

r_p4:
		live	%42						# 5
		st		r1,				r2		# 7
		ld		%4244860931,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p4_2:
		live	%42						# 5
		fork	%:r_p4_2				# 3
		zjmp	%-348					# 3

r_p5:
		live	%42						# 5
		ld		%167763715,		r2		# 7
		ld		%3993202691,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p5_2:
		live	%42						# 5
		fork	%:r_p5_2				# 3
		zjmp	%-432					# 3

init_forward:
		live	%42
		fork	%:p4
		live	%42
		fork	%:p3
		live	%42
		fork	%:p2
		live	%42
		fork	%:p1
		ld		%0,				r2	# carry = 1

alive:
		live	%42
		zjmp	%:alive

p1:
		ld		%57672192,		r2
		ld		%318992387,		r3
		ld		%0,				r4	# carry = 1
p1_2:
		live	%42
		fork	%:p1_2
		zjmp	%:move_forward

p2:
		live	%42
		ld		%251883523,		r2
		ld		%386101251,		r3
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
p2_2:
		live	%42
		fork	%:p2_2
		zjmp	%:move_forward

p3:
		live	%42
		ld		%4294902016,	r2
		ld		%436432899,		r3
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
		live	%42
		fork	%:alive
p3_2:
		live	%42
		fork	%:p3_2
		zjmp	%:move_forward

p4:
		live	%42
		st		r1,				r2
		ld		%251883523,		r3
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
		live	%42
		fork	%:alive
		live	%42
		fork	%:alive
p4_2:
		live	%42
		fork	%:p4_2
		zjmp	%:move_forward

move_forward:
		st		r2,				15
		st		r3,				-1
		live	%1337
